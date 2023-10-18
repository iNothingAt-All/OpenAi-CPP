#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

#include "ArchivoJson.hpp"

ArchivoJson::~ArchivoJson() {}
ArchivoJson::ArchivoJson(const std::string& archivo)
    : archivo{archivo}
{
    leer(archivo);
}


void ArchivoJson::leer(const std::string& archivo)
{
    std::ifstream contenido_archivo {archivo};

    if(contenido_archivo.fail())
    {
        std::cout << "[-] Archivo perdido: el archivo " +archivo+ " no se encuentra...\n";
        return;
    }

    contenido_archivo >> contenido;
}


void ArchivoJson::update()
{
   leer(archivo);
}


void ArchivoJson::escribir(const nlohmann::json& datos)
{
    std::ofstream contenido_archivo{archivo};
    
    if(contenido_archivo.fail())
    {
        std::cout << "[-] Archivo perdido: el archivo " +archivo+ " no se encuentra...\n";
        return;
    }

    contenido_archivo << datos.dump(4);
    contenido = datos;
}


std::string ArchivoJson::operator [](const std::string& key) 
{ 
    if (not contenido.contains(key)) 
    {
        std::cerr << "[-] Clave perdida: No se encuentra la clave '" +key+ "' en el archivo '" +archivo+ "'...\n"; 
        return "";
    }
    
    return contenido[key]; 
}

bool ArchivoJson::operator!() { return contenido.is_null(); }
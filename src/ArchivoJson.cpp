#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

#include "ArchivoJson.hpp"

ArchivoJson::~ArchivoJson() {}
ArchivoJson::ArchivoJson(const std::string& archivo)
    : archivo{archivo}
{
    std::ifstream contenido_archivo{archivo};     
    contenido_archivo >> contenido;
}

void ArchivoJson::escribir(nlohmann::json datos)
{
    std::ofstream contenido_archivo{archivo};
    contenido_archivo << datos.dump(4);
    contenido = datos;
}

std::string ArchivoJson::operator [](const std::string& key) 
{ 
    if (not contenido.contains(key)) {
        std::cerr << "[-] No se encuentra la clave '" << key <<"' en el archivo '" << archivo << "'...\n"; 
        return "";
    }
    
    return contenido[key]; 
}

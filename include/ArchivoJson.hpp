#pragma once
#include <nlohmann/json.hpp>
#include <string>

struct ArchivoJson
{
    std::string operator [](const std::string&);
    
    ArchivoJson(const std::string&);
    ~ArchivoJson();

    void escribir(nlohmann::json);

    nlohmann::json contenido;
    std::string archivo;
};
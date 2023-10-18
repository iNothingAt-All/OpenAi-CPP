#pragma once
#include <nlohmann/json.hpp>
#include <string>

struct ArchivoJson
{
    std::string operator [](const std::string&);
    bool operator!();

    ArchivoJson(const std::string&);
    ~ArchivoJson();

    void escribir(const nlohmann::json&);
    void leer(const std::string&);
    void actualizar();

    nlohmann::json contenido {};
    std::string archivo {" "};
};
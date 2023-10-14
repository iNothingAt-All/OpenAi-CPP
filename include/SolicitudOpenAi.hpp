#pragma once
#include <string>
#include <nlohmann/json.hpp>

#include "ConexionOpenAi.hpp"

struct SolicitudOpenAi : ConexionOpenAi
{
    SolicitudOpenAi(const std::string&, const std::string&);
    ~SolicitudOpenAi();

    bool openai_solicitud();

    static size_t atrapar_respuesta(char* contenido, size_t tamanyo, size_t cantidad, nlohmann::json& variable_respuesta)
    {
        variable_respuesta = nlohmann::json::parse(contenido);
        return tamanyo * cantidad;
    }

    nlohmann::json resultado = nlohmann::json::object();
};
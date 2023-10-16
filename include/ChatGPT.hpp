#pragma once
#include <string>
#include <initializer_list>
#include <nlohmann/json.hpp>

#include "SolicitudOpenAi.hpp"
#include "ArchivoJson.hpp"

struct ChatGPT : SolicitudOpenAi
{
    ~ChatGPT();
    ChatGPT(const std::string&, const std::string&);
    ChatGPT(const std::string&, const std::string&, const nlohmann::json::array_t&);

    void mensaje(const std::string&);
    void enviar();

    std::string modelo {" "};
    std::string respuesta {" "};

    nlohmann::json conversacion = nlohmann::json::array();
};
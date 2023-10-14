#pragma once
#include <string>
#include <initializer_list>
#include <nlohmann/json.hpp>

#include "SolicitudOpenAi.hpp"

struct ChatGPT : SolicitudOpenAi
{
    ChatGPT(const std::string&, const std::string&);
    ChatGPT(const std::string&, const std::string&, const std::initializer_list<nlohmann::json>&);
    
    ~ChatGPT();
    
    void mensaje(const std::string&);
    void enviar();

    std::string modelo {" "};
    std::string respuesta {" "};

    nlohmann::json mensajes = nlohmann::json::array();      
};
#pragma once
#include <string>
#include <nlohmann/json.hpp>

namespace MensajeGPT
{   
    inline nlohmann::json base_interaccion(const std::string& rol, const std::string& contenido) {
        return {{"role", rol}, {"content", contenido}};
    }

    inline nlohmann::json base_envio_chat(const std::string& modelo, const nlohmann::json& mensajes) {
        return {{"model", modelo}, {"messages", mensajes}};
    }

    nlohmann::json orden(const std::string& contenido);
    nlohmann::json interaccion(const std::string& contenido); 
    nlohmann::json respuesta(const std::string& contenido);
}
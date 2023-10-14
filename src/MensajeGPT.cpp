#include <string> 
#include <nlohmann/json.hpp>

#include "MensajeGPT.hpp"

namespace MensajeGPT
{
    nlohmann::json orden(const std::string& contenido) { return base_interaccion("system", contenido); }
    nlohmann::json interaccion(const std::string& contenido) { return base_interaccion("user", contenido); }
    nlohmann::json respuesta(const std::string& contenido) { return base_interaccion("assistant", contenido); }
};
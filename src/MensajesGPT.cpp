#include <string> 
#include <nlohmann/json.hpp>

#include "MensajesGPT.hpp"

namespace MensajesGPT
{
    nlohmann::json orden(const std::string& contenido) { return base_interaccion("system", contenido); }
    nlohmann::json interaccion(const std::string& contenido) { return base_interaccion("user", contenido); }
    nlohmann::json respuesta(const std::string& contenido) { return base_interaccion("assistant", contenido); }
};
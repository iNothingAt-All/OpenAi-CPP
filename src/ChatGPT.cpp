#include <string>
#include <initializer_list>
#include <nlohmann/json.hpp>

#include "ChatGPT.hpp"
#include "SolicitudOpenAi.hpp"
#include "MensajeGPT.hpp"

ChatGPT::~ChatGPT() {}
ChatGPT::ChatGPT(const std::string& modelo, const std::string& api_key) 
    : SolicitudOpenAi{"https://api.openai.com/v1/chat/completions", api_key}, modelo{modelo}
{}


ChatGPT::ChatGPT(const std::string& modelo, const std::string& api_key, const nlohmann::json::array_t& contexto) 
    : ChatGPT{modelo, api_key} 
{ 
    conversacion = contexto;
}


void ChatGPT::mensaje(const std::string& contenido)
{
    conversacion.push_back(MensajeGPT::interaccion(contenido));    
    enviar_campo(MensajeGPT::base_envio_chat(modelo, conversacion).dump());
}


void ChatGPT::enviar() 
{
    if(not openai_solicitud()) return;

    conversacion.push_back(resultado["choices"][0]["message"]);
    respuesta = conversacion.back()["content"].dump(); 
}

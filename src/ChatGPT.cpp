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

ChatGPT::ChatGPT(const std::string& modelo, const std::string& api_key, const std::initializer_list<nlohmann::json>& contexto) 
    : ChatGPT{modelo, api_key} { mensajes = contexto; }

void ChatGPT::mensaje(const std::string& mensaje)
{
    mensajes.push_back(MensajeGPT::interaccion(mensaje));
    enviar_campo(MensajeGPT::base_envio_chat(modelo, mensajes).dump());
}

void ChatGPT::enviar() 
{
    if(not openai_solicitud()) return;

    mensajes.push_back(resultado["choices"][0]["message"]);
    respuesta = mensajes.back()["content"].dump(); 
}

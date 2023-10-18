#include <iostream>
#include <string>

#include "ChatGPT.hpp"
#include "ArchivoJson.hpp"

int main()
{
    std::string mensaje {" "};
    ArchivoJson configuracion {"configuracion.json"};    
    ArchivoJson contexto {"conversacion.json"};
    
    if(!configuracion or !contexto) return 1;

    ChatGPT chat(
        configuracion["modelo_chat"], 
        configuracion["key"],
        contexto.contenido
    );

    for(int interacciones = 0; interacciones < 5; ++interacciones) 
    {
        std::cout << ">> "; std::getline(std::cin, mensaje);

        chat.mensaje(mensaje);
        chat.enviar();

        std::cout << chat.respuesta + "\n\n";
        contexto.escribir(chat.conversacion);
    }

    return 0;
}
#include <iostream>
#include <string>

#include "ChatGPT.hpp"
#include "ArchivoJson.hpp"

int main()
{
    std::string mensaje {" "};
    ArchivoJson configuracion {"configuracion.json"};    
    ArchivoJson contexto {"conversacion.json"};
    
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
        contexto.actualizar();
    }

    return 0;
}

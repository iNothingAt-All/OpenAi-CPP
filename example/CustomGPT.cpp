#include <iostream>
#include <string>

#include "MensajesGPT.hpp"
#include "ChatGPT.hpp"
#include "ArchivoJson.hpp"

int main()
{
    ArchivoJson configuracion{"configuracion.json"};

    ChatGPT chat(
        configuracion["modelo_chat"], 
        configuracion["key"],
    {        
        // Ordenes de comportamiento
        MensajesGPT::orden("Vas a traducir todo lo que te digan a ingles"),
        MensajesGPT::orden("Tu respuesta desde tener 'Translation -> '"),

        // Ejemplos de interaccion
        MensajesGPT::interaccion("Hola"),
        MensajesGPT::respuesta("Translation -> Hello"),
        MensajesGPT::interaccion("Mi nombre es Luis"),
        MensajesGPT::respuesta("Translation -> My name is Luis")
    });

    chat.mensaje("hola");
    chat.enviar();

    std::cout << chat.respuesta;

    return 0;
}
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
        configuracion["key"]
    );

    chat.mensaje("hola");
    chat.enviar();

    std::cout << chat.respuesta;

    return 0;
}
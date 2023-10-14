# OpenAi-CPP
Una adaptación de la API de OpenAi a C++

## Librerías
- [nlohmann/json](https://github.com/nlohmann/json)
- [curl](https://curl.se/)

## Configuración
Debe especificar su "key" de OpenAI API y un modelo acorde a su plan de la API

```json
{
    "key": "sk-...  qa6",
    "modelo_chat": "gpt-3.5-turbo"
}
```

## Ejecución y Construccion
Por facilidad están los archivos `_build.sh` y `_run.sh` que ayudarán a la generación de archivo binario y su ejecución por consola


## Personalización de IA
En caso de querer respuestas o comportamientos personalizados se le puede pasar un contexto o listado de ordenes que definan como debe actuar la IA.

```cpp
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
```
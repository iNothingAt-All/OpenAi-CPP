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
ChatGPT chat(
    configuracion["modelo_chat"], 
    configuracion["key"],
{        
    // Ordenes de comportamiento
    MensajeGPT::orden("Vas a traducir todo lo que te digan a ingles"),
    MensajeGPT::orden("Tu respuesta desde tener 'Translation -> '"),

    // Ejemplos de interaccion
    MensajeGPT::interaccion("Hola"),
    MensajeGPT::respuesta("Translation -> Hello"),
    MensajeGPT::interaccion("Mi nombre es Luis"),
    MensajeGPT::respuesta("Translation -> My name is Luis")
});
```
# OpenAi-CPP
Una adaptación de la API de OpenAi a C++

## Librerías
- [nlohmann/json](https://github.com/nlohmann/json)
- [curl](https://curl.se/)

## Configuración
Debe especificar su "key" de **OpenAI API** y un modelo acorde a su plan de la API

`configuracion.json`
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

`Main.cpp`
```cpp
ArchivoJson configuracion {"configuracion.json"};

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
.
.
.
```

El contexto también puede provenir de un archivo externo que contenta todas las instrucciones de comportamiento o conversaciones pasadas para retomarlas.

`comportamiento.json`
```json
[
    {"role": "system", "content": "Vas a traducir todo lo que te digan a ingles"},
    {"role": "system", "content": "Tu respuesta desde tener 'Translation -> '"},

    {"role": "user", "content": "Hola"},
    {"role": "assistant", "content": "Translation -> Hello"},
    {"role": "user", "content": "Mi nombre es Luis"},
    {"role": "assistant", "content": "Translation -> My name is Luis"}
]
```
`Main.cpp`
```cpp
ArchivoJson configuracion {"configuracion.json"};
ArchivoJson comportamiento  {"comportamiento .json"};

ChatGPT chat(
    configuracion["modelo_chat"], 
    configuracion["key"],

    comportamiento.contenido
);
.
.
.
```

Las conversaciones se podrán guardar mediante el método **escribir** de la clase **ArchivoJson** al igual que actualizar el contenido del archivo en tiempo de ejecución mediante **actualizar**.

```cpp
.
.
.
for(int interacciones = 0; interacciones < 5; ++interacciones) 
{
    std::cout << ">> ";  std::getline(std::cin, mensaje);

    chat.mensaje(mensaje);
    chat.enviar();

    std::cout << chat.respuesta + "\n\n";
    contexto.escribir(chat.conversacion);
    contexto.actualizar();
}
```

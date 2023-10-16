#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "SolicitudOpenAi.hpp"
#include "ConexionOpenAi.hpp"

SolicitudOpenAi::~SolicitudOpenAi() {}
SolicitudOpenAi::SolicitudOpenAi(const std::string& api_url, const std::string& api_key)
    : ConexionOpenAi{api_url, api_key}
{
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, atrapar_respuesta);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resultado);
}


bool SolicitudOpenAi::openai_solicitud()
{
    if(not curl_solicitud()) return false;

    bool hay_error {resultado.contains("error")};
    bool envio_solicitud {not hay_error};

    if(hay_error) {
        std::cerr << "[-] Informe Openai: " << resultado["error"]["message"] << "...\n";
    }

    return envio_solicitud;
}
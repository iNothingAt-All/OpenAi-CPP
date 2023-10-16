#include <curl/curl.h>
#include <iostream>
#include <string>

#include "SolicitudCUrl.hpp"
#include "ConexionCUrl.hpp"

SolicitudCUrl::~SolicitudCUrl() {}
SolicitudCUrl::SolicitudCUrl(const std::string& url) 
    : ConexionCUrl{url}
{}


void SolicitudCUrl::enviar_campo(const std::string& campo) {
    curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, campo.c_str());
}


bool SolicitudCUrl::curl_solicitud()
{
    CURLcode informe_solicitud {curl_easy_perform(curl)};
    bool envio_solicitud {informe_solicitud == CURLE_OK};

    if(not envio_solicitud) {
        std::cerr << "[-] Informe Curl: " << curl_easy_strerror(informe_solicitud) << "...\n";
    }

    return envio_solicitud;
}
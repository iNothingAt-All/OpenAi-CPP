#pragma once
#include <string>

#include "ConexionCUrl.hpp"

struct SolicitudCUrl : ConexionCUrl
{
    SolicitudCUrl(const std::string&);
    ~SolicitudCUrl();

    void enviar_campo(const std::string&);
   
    bool curl_solicitud();
};
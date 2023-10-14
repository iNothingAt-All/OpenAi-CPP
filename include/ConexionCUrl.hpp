#pragma once
#include <string>
#include <curl/curl.h>

struct ConexionCUrl
{
    ConexionCUrl(const std::string&);
    ~ConexionCUrl();

    void encabezados_http(const std::string&, const std::string&);

    CURL* curl {nullptr};
};
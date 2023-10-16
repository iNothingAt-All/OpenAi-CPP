#include <string> 
#include <curl/curl.h>

#include "ConexionCUrl.hpp"

ConexionCUrl::~ConexionCUrl() { curl_easy_cleanup(curl); }
ConexionCUrl::ConexionCUrl(const std::string& url) 
    : curl{curl_easy_init()} 
{
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
}


void ConexionCUrl::encabezados_http(const std::string& contenido, const std::string& autenticacion)
{
    curl_slist* encabezados {nullptr};
    encabezados = curl_slist_append(encabezados, ("Content-Type: "+ contenido).c_str());
    encabezados = curl_slist_append(encabezados, ("Authorization: Bearer " + autenticacion).c_str());
    encabezados = curl_slist_append(encabezados, "charset=UTF-8");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, encabezados);     
}
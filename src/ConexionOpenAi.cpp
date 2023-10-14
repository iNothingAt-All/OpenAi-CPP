#include <string>

#include "ConexionOpenAi.hpp"
#include "SolicitudCUrl.hpp"

ConexionOpenAi::~ConexionOpenAi() {}
ConexionOpenAi::ConexionOpenAi(const std::string& api_url, const std::string& api_key)
    : SolicitudCUrl{api_url} { encabezados_http("application/json", api_key); }
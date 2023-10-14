#pragma once
#include <string>

#include "SolicitudCUrl.hpp"

struct ConexionOpenAi : SolicitudCUrl
{
    ConexionOpenAi(const std::string&, const std::string&);
    ~ConexionOpenAi();
};
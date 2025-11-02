//
// Created by gbrito11 on 19/10/2025.
//

#include "Regador.h"

Regador::Regador() : Ferramenta() {
    type = 'g';
    capacidade = Settings::Regador::capacidade;
}

Regador::~Regador() {}

void Regador::usa(Celula& cell) {
    // implementar depois
}

bool Regador::vazio() {
    // implementar depois
    return false;
}

std::string Regador::Info() {
    // implementar depois
    return "";
}
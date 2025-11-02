//
// Created by gbrito11 on 19/10/2025.
//

#include "Adubo.h"
Adubo::Adubo() : Ferramenta() {
    type = 'a';
    capacidade = Settings::Adubo::capacidade;
}

Adubo::~Adubo() {}

void Adubo::usa(Celula& cell) {
    // implementar depois
}

bool Adubo::vazio() {
    // implementar depois
    return false;
}

std::string Adubo::Info() {
    // implementar depois
    return "";
}
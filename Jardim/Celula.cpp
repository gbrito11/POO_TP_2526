//
// Created by gbrito11 on 18/10/2025.
//

#include "Celula.h"
#include <iostream>

char Celula::mostrar() const {
    return conteudo;
}

Celula::Celula(char c) : conteudo(c) {}
Celula::Celula(){}

//
// Created by gbrito11 on 02/11/2025.
//

#include "FerramentaZ.h"

#include <iostream>
#include <sstream>
#include "../Settings.h"
#include "../Jardim/Celula.h"
#include "../Planta/Planta.h"

Dreno::Dreno() : Ferramenta() {
    type = 'Z';
}

Dreno::~Dreno() {}

void Dreno::usa(Celula& cell) {
    // 1. Verifica se o Dreno ainda funciona
    if (capacidade <= 0) {
        std::cout << "O Dreno esta entupido/gasto.\n";
        return;
    }

    // 2. Ação: Drenar água do SOLO
    int aguaAtual = cell.getAgua();

    if (aguaAtual > 0) {
        int novaAgua = aguaAtual - DOSE_DRENAGEM;
        if (novaAgua < 0) novaAgua = 0; // Não deixa ficar negativo

        cell.setAgua(novaAgua);
        std::cout << "Drenaste " << DOSE_DRENAGEM << " de agua do solo.\n";

        // Gasta a ferramenta
        capacidade -= DOSE_DRENAGEM;
    } else {
        std::cout << "O solo ja esta seco.\n";
    }



    if (cell.getPlanta() != nullptr) {
    cell.getPlanta()->takeAgua(); // Usa a função takeAgua da planta
    }
}

bool Dreno::vazio() {
    return this->capacidade <= 0;
}

std::string Dreno::Info() {
    std::stringstream ss;
    ss << "Dreno [ID:" << serialNum << "] - Capacidade: " << capacidade;
    return ss.str();
}
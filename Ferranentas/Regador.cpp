//
// Created by gbrito11 on 19/10/2025.
//

#include "Regador.h"

#include <iostream>
#include <sstream>

#include "../Settings.h"
#include "../Jardim/Celula.h"
#include "../Planta/Planta.h"

Regador::Regador() : Ferramenta() {
    type = 'g';
    capacidade = Settings::Regador::capacidade;
}

Regador::~Regador() {}

void Regador::usa(Celula& cell) {
    // 1. Verifica se tem água
    if (this->capacidade < Settings::Regador::dose) {
        std::cout << "O Regador esta vazio! Tens de comprar outro.\n";
        return;
    }

    // 2. Aplica a ação
    bool usou = false;

    // Se houver planta, dá água à planta
    if (cell.getPlanta() != nullptr) {
        cell.getPlanta()->darAgua();
        std::cout << "Regaste a planta (" << Settings::Regador::dose << " agua).\n";
        usou = true;
    }
    // Se não houver planta, molha o solo (opcional, mas útil)
    else {
        int novaAgua = cell.getAgua() + Settings::Regador::dose;
        // Respeita o máximo do jardim (100) se quiseres
        if (novaAgua > Settings::Jardim::agua_max) novaAgua = Settings::Jardim::agua_max;

        cell.setAgua(novaAgua);
        std::cout << "Deitaste agua no solo.\n";
        usou = true;
    }

    // 3. Gasta a capacidade
    if (usou) {
        this->capacidade -= Settings::Regador::dose;
        std::cout << "Capacidade restante do Regador: " << this->capacidade << "\n";
    }
}

bool Regador::vazio() {
    return this->capacidade<=0;
}

std::string Regador::Info() {
    std::stringstream ss;
    ss << "Saco de Adubo [ID:" << this->serialNum << "] - Nutrientes restantes: " << this->capacidade;
    return ss.str();
}
//
// Created by gbrito11 on 19/10/2025.
//

#include "Adubo.h"

#include <iostream>
#include <sstream>

#include "../Settings.h"
#include "../Jardim/Celula.h"
#include "../Planta/Planta.h"

Adubo::Adubo() : Ferramenta() {
    type = 'a';
    capacidade = Settings::Adubo::capacidade;
}

Adubo::~Adubo() {}

void Adubo::usa(Celula& cell) {
    if (this->capacidade < Settings::Adubo::dose) {
        std::cout << "O Saco de Adubo esta vazio! O vento levou-o...\n";
        return;
    }

    // 2. Aplica a ação
    bool usou = false;

    // Se houver planta, alimenta a planta
    if (cell.getPlanta() != nullptr) {
        cell.getPlanta()->darNutrientes();
        std::cout << "Adubaste a planta (" << Settings::Adubo::dose << " nutrientes).\n";
        usou = true;
    }
    // Se não houver planta, aduba o solo
    else {
        int novosNutri = cell.getNutrientes() + Settings::Adubo::dose;
        // Respeita o máximo do jardim (50) se quiseres
        if (novosNutri > Settings::Jardim::nutrientes_max) novosNutri = Settings::Jardim::nutrientes_max;

        cell.setNutrientes(novosNutri);
        std::cout << "Adubaste o solo.\n";
        usou = true;
    }

    // 3. Gasta a capacidade
    if (usou) {
        this->capacidade -= Settings::Adubo::dose;
        std::cout << "Capacidade restante do Adubo: " << this->capacidade << "\n";
    }
}

bool Adubo::vazio() {
    return this->capacidade <= 0;
}

std::string Adubo::Info() {
    std::stringstream ss;
    ss << "Regador [ID:" << this->serialNum << "] - Agua restante: " << this->capacidade;
    return ss.str();
}
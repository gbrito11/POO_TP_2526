//
// Created by gbrito11 on 19/10/2025.
//

#include "Tesoura.h"

#include <iostream>
#include <sstream>

#include "../Settings.h"
#include "../Jardim/Celula.h"
#include "../Planta/Planta.h"


Tesoura::Tesoura() : Ferramenta() {
    type = 't';
}

Tesoura::~Tesoura() {}

void Tesoura::usa(Celula& cell) {
    if (cell.getPlanta() != nullptr) {
        // Se a planta for feia (Erva Daninha), corta-a!
        // (Podes verificar pelo tipo 'e' ou pelo getBeauty() == "feio")
        if (cell.getPlanta()->getType() == 'e') {
            std::cout << "Cortaste uma Erva Daninha!\n";
            cell.removePlanta(); // Adeus planta
        } else {
            std::cout << "Esta planta e bonita, nao a deves cortar.\n";
        }
    }
}

bool Tesoura::vazio() {
    //nunca fica vazia
    return false;
}

std::string Tesoura::Info() {
    std::stringstream ss;
    ss << "Tesoura de Poda [ID:" << this->serialNum << "] - Infinita";
    return ss.str();
}
//
// Created by gbrito11 on 19/10/2025.
//

#include "Roseira.h"

Roseira::Roseira() : Planta("bonito") {
    type = 'r';

    agua = Settings::Roseira::inicial_agua;        // 25
    nutrientes = Settings::Roseira::inicial_nutrientes;  // 25
}

Roseira::~Roseira() {
    // logica do delete
}

void Roseira::time() {
    // implementar depois
}

void Roseira::multiplica() {
    // implementar depois
}

bool Roseira::deveMorrer() {
    // implementar depois
    return false;
}

void Roseira::takeAgua() {
    // implementar depois
}

void Roseira::takeNutrientes() {
    // implementar depois
}

void Roseira::darAgua() {
    // implementar depois
}

void Roseira::darNutrientes() {
    // implementar depois
}
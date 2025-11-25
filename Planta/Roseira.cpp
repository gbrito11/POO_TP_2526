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

void Roseira::processaTempo(Celula& celula) {
    // O teu código aqui...
}

void Roseira::efeitoMorte(Celula& celula) {
    // O teu código aqui...
}

void Roseira::multiplica(Celula& celula) { // <-- O ERRO PROVAVELMENTE É ESTA
    // Se ainda não tens lógica, deixa o corpo vazio, mas a função TEM DE EXISTIR
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
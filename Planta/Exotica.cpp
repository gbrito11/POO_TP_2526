//
// Created by gbrito11 on 19/10/2025.
//

#include "Exotica.h"
#include "../Settings.h"
#include "../Jardim/Celula.h"
#include "../Jardim/Jardim.h"


Exotica::Exotica() : Planta("neutro") {
    type = 'x';

    agua = 30;
    nutrientes = 15;

}
Exotica::~Exotica() {
    // logica do delete
}


int Exotica::getChuva() { return 20; }
// --- VIDA ---
void Exotica::processaTempo(Celula& celula) {
    this->idade++;
    // Exemplo: Ela não gasta nada, é mágica!
    // Ou podes pôr a gastar um pouco de nutrientes para não ser imortal
}

bool Exotica::deveMorrer() {
    // Exemplo: Morre se ficar muito velha (> 2000 instantes)
    return this->idade > 50;
}

void Exotica::efeitoMorte(Celula& celula) {
    // Quando morre, deixa adubo extra
    celula.setNutrientes(celula.getNutrientes() + 50);
}

// --- REPRODUÇÃO ---
bool Exotica::querMultiplicar() {
    // Exemplo: Nunca se multiplica sozinha (é única)
    return false;
}

Planta* Exotica::reproduz() {
    return nullptr; // Não cria filhos
}


void Exotica::takeAgua() {
    // implementar depois
}

void Exotica::takeNutrientes() {
    // implementar depois
}

void Exotica::darAgua() {
    // implementar depois
}

void Exotica::darNutrientes() {
    // implementar depois
}
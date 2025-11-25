//
// Created by gbrito11 on 19/10/2025.
//

#include "Exotica.h"

Exotica::Exotica() : Planta("neutro") {
    type = 'x';

    agua = 30;
    nutrientes = 15;

}
Exotica::~Exotica() {
    // logica do delete
}

void Exotica::processaTempo(Celula& celula) {
    // O teu código aqui...
}

void Exotica::efeitoMorte(Celula& celula) {
    // O teu código aqui...
}

void Exotica::multiplica(Celula& celula) { // <-- O ERRO PROVAVELMENTE É ESTA
    // Se ainda não tens lógica, deixa o corpo vazio, mas a função TEM DE EXISTIR
}

bool Exotica::deveMorrer() {
    // implementar depois
    return false;
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
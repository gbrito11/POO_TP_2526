//
// Created by gbrito11 on 19/10/2025.
//

#include "ErvaDaninha.h"

ErvaDaninha::ErvaDaninha() : Planta("feio") {
    type = 'e';


    agua = Settings::ErvaDaninha::inicial_agua;
    nutrientes = Settings::ErvaDaninha::inicial_nutrientes;

    timeNascimento = 0;
}

ErvaDaninha::~ErvaDaninha() {
    // logica do delete
}

void ErvaDaninha::processaTempo(Celula& celula) {
    // O teu código aqui...
}

void ErvaDaninha::efeitoMorte(Celula& celula) {
    // O teu código aqui...
}

void ErvaDaninha::multiplica(Celula& celula) { // <-- O ERRO PROVAVELMENTE É ESTA
    // Se ainda não tens lógica, deixa o corpo vazio, mas a função TEM DE EXISTIR
}

bool ErvaDaninha::deveMorrer() {
    // implementar depois
    return false;
}

void ErvaDaninha::takeAgua() {
    // implementar depois
}

void ErvaDaninha::takeNutrientes() {
    // implementar depois
}

void ErvaDaninha::darAgua() {
    // implementar depois
}

void ErvaDaninha::darNutrientes() {
    // implementar depois
}
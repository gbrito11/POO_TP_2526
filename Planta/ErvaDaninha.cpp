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

void ErvaDaninha::time() {
    // implementar depois
}

void ErvaDaninha::multiplica() {
    // implementar depois
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
//
// Created by gbrito11 on 19/10/2025.
//

#include "ErvaDaninha.h"
#include "../Settings.h"
#include "../Jardim/Celula.h"


ErvaDaninha::ErvaDaninha() : Planta("feio") {
    type = 'e';


    agua = Settings::ErvaDaninha::inicial_agua;
    nutrientes = Settings::ErvaDaninha::inicial_nutrientes;

    instantesSemReproduzir= 0;
}

ErvaDaninha::~ErvaDaninha() {
    // logica do delete
}

void ErvaDaninha::processaTempo(Celula& celula) {
    this->idade++;
    this->instantesSemReproduzir++; // Conta o tempo para poder reproduzir

    // Absorve pouco (1 unidade)
    int aguaSolo = celula.getAgua();
    int nutriSolo = celula.getNutrientes();

    int beber = std::min(aguaSolo, (int)Settings::ErvaDaninha::absorcao_agua);
    int comer = std::min(nutriSolo, (int)Settings::ErvaDaninha::absorcao_nutrientes);

    celula.setAgua(aguaSolo - beber);
    this->agua += beber;

    celula.setNutrientes(nutriSolo - comer);
    this->nutrientes += comer;
}

bool ErvaDaninha::deveMorrer() {
    // Morre de velhice (60 instantes)
    return this->idade >= Settings::ErvaDaninha::morre_instantes;
}

void ErvaDaninha::efeitoMorte(Celula& celula) {
    // O enunciado não especifica, mas podes devolver tudo
    celula.setNutrientes(celula.getNutrientes() + this->nutrientes);
    celula.setAgua(celula.getAgua() + this->agua);
}

// --- REPRODUÇÃO ---
bool ErvaDaninha::querMultiplicar() {
    // Nutri > 30 E passaram 5 instantes
    return (this->nutrientes > Settings::ErvaDaninha::multiplica_nutrientes_maior &&
            this->instantesSemReproduzir >= Settings::ErvaDaninha::multiplica_instantes);
}

Planta* ErvaDaninha::reproduz() {
    ErvaDaninha* filha = new ErvaDaninha();
    // Filha nasce padrão. Mãe não perde nada, só reseta o tempo.
    this->instantesSemReproduzir = 0;
    return filha;
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
//
// Created by gbrito11 on 19/10/2025.
//

#include "Roseira.h"
#include "../Settings.h"
#include "../Jardim/Celula.h"

Roseira::Roseira() : Planta("bonito") {
    type = 'r';

    agua = Settings::Roseira::inicial_agua;        // 25
    nutrientes = Settings::Roseira::inicial_nutrientes;  // 25
}

Roseira::~Roseira() {
    // logica do delete
}

void Roseira::processaTempo(Celula& celula) {
    this->idade++;

    // 1. GASTO METABÓLICO (Perde vida só por existir)
    if (this->agua >= Settings::Roseira::perda_agua)
        this->agua -= Settings::Roseira::perda_agua;
    else this->agua = 0;

    if (this->nutrientes >= Settings::Roseira::perda_nutrientes)
        this->nutrientes -= Settings::Roseira::perda_nutrientes;
    else this->nutrientes = 0;

    // 2. ABSORVER DO SOLO
    int aguaSolo = celula.getAgua();
    int nutriSolo = celula.getNutrientes();

    // Usa (int) para evitar erro de linker
    int beber = std::min(aguaSolo, (int)Settings::Roseira::absorcao_agua);
    int comer = std::min(nutriSolo, (int)Settings::Roseira::absorcao_nutrientes);

    celula.setAgua(aguaSolo - beber);
    this->agua += beber;

    celula.setNutrientes(nutriSolo - comer);
    this->nutrientes += comer;
}

bool Roseira::deveMorrer() {
    // Morre se ficar a 0 ou se tiver nutrientes a mais (> 200)
    if (this->agua <= 0) return true;
    if (this->nutrientes <= 0) return true;
    if (this->nutrientes > Settings::Roseira::morre_nutrientes_maior) return true;
    return false;
}

void Roseira::efeitoMorte(Celula& celula) {
    // Devolve METADE ao solo
    celula.setNutrientes(celula.getNutrientes() + (this->nutrientes / 2));
    celula.setAgua(celula.getAgua() + (this->agua / 2));
}

// --- REPRODUÇÃO ---
bool Roseira::querMultiplicar() {
    return this->nutrientes > Settings::Roseira::multiplica_nutrientes_maior;
}

Planta* Roseira::reproduz() {
    Roseira* filha = new Roseira();

    // Filha: 25 nutri, 50% água da mãe
    filha->nutrientes = Settings::Roseira::nova_nutrientes;
    filha->agua = this->agua * Settings::Roseira::nova_agua_percentagem / 100;

    // Mãe: Fica com 100 nutri, perde 50% água
    this->nutrientes = Settings::Roseira::original_nutrientes;
    this->agua = this->agua * Settings::Roseira::original_agua_percentagem / 100;

    return filha;
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
//
// Created by gbrito11 on 19/10/2025.
//

#include "Cacto.h"

#include <iostream>

#include "../Settings.h"
#include "../Jardim/Celula.h"


Cacto::Cacto() : Planta("neutro") {
    type = 'c';

    // prencher com valores da planta mais tade
    agua = 0;
    nutrientes = 0;
}

Cacto::~Cacto() {
    // logica do delete
}
void Cacto::processaTempo(Celula& celula){
    this->idade++;

    // --- ABSORVER ÁGUA (25% do que está no solo) ---
    int aguaNoSolo = celula.getAgua();
    int aguaAbeber = aguaNoSolo * Settings::Cacto::absorcao_agua_percentagem / 100;

    celula.setAgua(aguaNoSolo - aguaAbeber); // Tira do solo
    this->agua += aguaAbeber;                // Guarda na planta

    // --- ABSORVER NUTRIENTES (Até 5) ---
    int nutriNoSolo = celula.getNutrientes();
    int nutriAComer = std::min((int)Settings::Cacto::absorcao_nutrientes, nutriNoSolo);

    celula.setNutrientes(nutriNoSolo - nutriAComer);
    this->nutrientes += nutriAComer;

    // --- VERIFICAR CONDIÇÕES DE MORTE (Contadores) ---

    // Água a mais? (> 100)
    if (celula.getAgua() > Settings::Cacto::morre_agua_solo_maior) {
        this->timeExtraAgua++;
    } else {
        this->timeExtraAgua = 0; // Reset se estiver normal
    }

    // Nutrientes a menos? (== 0)
    if (celula.getNutrientes() <= Settings::Cacto::morre_nutrientes_solo_menor) { // <= 0 ou 1
        this->timeSemNutrientes++;
    } else {
        this->timeSemNutrientes = 0; // Reset se estiver normal
    }

    std::cout<<"cacto modificado!!";
}
// 2. VERIFICAR SE DEVE MORRER
bool Cacto::deveMorrer() {
    // Morre se água > 100 por 3 turnos OU sem nutrientes por 3 turnos
    if (timeExtraAgua >= Settings::Cacto::morre_agua_solo_instantes) return true;
    if (timeSemNutrientes >= Settings::Cacto::morre_nutrientes_solo_instantes) return true;

    return false;
}

// 3. EFEITO QUANDO MORRE
void Cacto::efeitoMorte(Celula& celula) {
    // "Ao morrer deixa no solo todos os nutrientes que absorveu"
    int nutrientesAtuaisSolo = celula.getNutrientes();
    celula.setNutrientes(nutrientesAtuaisSolo + this->nutrientes);

    // (A água perde-se, segundo o enunciado)
}

// 4. MULTIPLICAÇÃO (Implementaremos depois no Jardim)
void Cacto::multiplica(Celula& celula) {
    // Lógica futura
}


void Cacto::takeAgua() {
    // implementar depois
}

void Cacto::takeNutrientes() {
    // implementar depois
}

void Cacto::darAgua() {
    // implementar depois
}

void Cacto::darNutrientes() {
    // implementar depois
}
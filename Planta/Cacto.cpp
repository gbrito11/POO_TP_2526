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
        this->timeExtraAgua = 0;
    }

    // Nutrientes a menos? (== 0)
    if (celula.getNutrientes() <= Settings::Cacto::morre_nutrientes_solo_menor) { // <= 0 ou 1
        this->timeSemNutrientes++;
    } else {
        this->timeSemNutrientes = 0;
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

bool Cacto::querMultiplicar() {

    return (this->nutrientes > Settings::Cacto::multiplica_nutrientes_maior &&
            this->agua > Settings::Cacto::multiplica_agua_maior);
}

Planta* Cacto::reproduz() {
    Cacto* filho = new Cacto();

    // Regra: "Divididos em iguais partes"
    int metadeAgua = this->agua / 2;
    int metadeNutri = this->nutrientes / 2;

    // 1. O Filho recebe metade
    filho->agua = metadeAgua;
    filho->nutrientes = metadeNutri;

    // 2. O Pai fica com a outra metade (perde o que deu)
    this->agua -= metadeAgua;
    this->nutrientes -= metadeNutri;

    return filho;
}

void Cacto::darAgua() {
    // Aumenta a água da planta com a dose definida nos Settings
    this->agua += Settings::Regador::dose;

    // Opcional: Limitar ao máximo se quiseres
    // if (this->agua > 100) this->agua = 100;
}

// O Adubo chama isto
void Cacto::darNutrientes() {
    this->nutrientes += Settings::Adubo::dose;
}

// O Dreno chama isto
void Cacto::takeAgua() {
    // Retira água (usa a mesma dose ou um valor fixo)
    this->agua -= Settings::Regador::dose;
    if (this->agua < 0) this->agua = 0;
}

// Outra ferramenta chama isto
void Cacto::takeNutrientes() {
    this->nutrientes -= Settings::Adubo::dose;
    if (this->nutrientes < 0) this->nutrientes = 0;
}
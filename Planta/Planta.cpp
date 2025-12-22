//
// Created by gbrito11 on 19/10/2025.
//

#include "Planta.h"


Planta::Planta(std::string inputBeauty)
    : beauty(inputBeauty),
      type(' '),
      idade(0),
      timeSemAgua(0),
      timeSemNutrientes(0),
      viva(true),
      agua(0),
      nutrientes(0)
{}
Planta::~Planta() {}

char Planta::getType() {
    return type;
}
void Planta::setIdade(int x) {
    this->idade=x;
}

std::string Planta::getBeauty() {
    return beauty;
}

bool Planta::Viva() {
    return viva;
}

int Planta::getAgua() {
    return agua;
}

int Planta::getNutrientes() {
    return nutrientes;
}

int Planta::getIdade() {
    return idade;
}
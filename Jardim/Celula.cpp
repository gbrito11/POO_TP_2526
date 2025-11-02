//
// Created by gbrito11 on 18/10/2025.
//

#include "Celula.h"
#include <iostream>

#include "../Ferranentas/Ferramenta.h"
#include "../Planta/Planta.h"

char Celula::mostrar() const {
    return type;
}



Celula::Celula() : agua(0), nutrientes(0), planta(nullptr), ferramenta(nullptr),type(' ') {
    // IMPORTANTE: Inicializar todos os ponteiros a nullptr para evitar segmentation errors
}

Celula::~Celula() {
    // logica parcial do destructor
    if (planta != nullptr) {
        delete planta;
        planta = nullptr;
    }
    if (ferramenta != nullptr) {
        delete ferramenta;
        ferramenta = nullptr;
    }
}

int Celula::getAgua() {
    return agua;
}

int Celula::getNutrientes() {
    return nutrientes;
}

Planta* Celula::getPlanta() {
    return planta;
}

Ferramenta* Celula::getFerramenta() {
    return ferramenta;
}

void Celula::setAgua(int a) {
    this->agua = a;
}

void Celula::setNutrientes(int n) {
    this->nutrientes = n;
}

void Celula::setPlanta(Planta* p) {
    this->planta = p;
    std::cout << "Planta colocada: " << p->getType() << std::endl;
}

void Celula::setFerramenta(Ferramenta* t) {
    // apagar a cena anterior para evitar memory leaks
    if (this->ferramenta != nullptr && this->ferramenta != t) {
        delete this->ferramenta;
    }
    this->ferramenta = t;
}

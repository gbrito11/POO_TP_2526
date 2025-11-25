//
// Created by gbrito11 on 19/10/2025.
//

#include "Jardineiro.h"

#include "Jardineiro.h"

#include <iostream>

#include "Settings.h"
#include "Ferranentas/Ferramenta.h"


Jardineiro::Jardineiro()
: line(0), col(0), nojardim(false), ferramenta(nullptr), contMovimentos(0),contColheitas(0)
, contPlantar(0), contEntradas(0){

}

Jardineiro::~Jardineiro() {
    for (Ferramenta* ferramenta : ferramentas) {
        delete ferramenta; // clean up futuro, atualmente o tool nem tem destructor
    }
    ferramentas.clear(); // limpa o array
    ferramenta = nullptr;
}

int Jardineiro::getMaxMove() {
    return Settings::Jardineiro::max_movimentos;
}

int Jardineiro::getMaxEntradas() {
    return Settings::Jardineiro::max_entradas_saidas;
}

int Jardineiro::getMaxPlantacoes() {
    return Settings::Jardineiro::max_plantacoes;
}

int Jardineiro::getMaxColheitas() {
    return Settings::Jardineiro::max_colheitas;
}

void Jardineiro::adicionaFerr(Ferramenta* ferramenta) {
    // implementar depois
}

void Jardineiro::removeFerr(int serialNum) {
    // implementar depois
    // NAO ESQUECER DE DESTRUIR A TOOL ANTES DE REMOVER
}

void Jardineiro::setFerr(int serialNum) {
    // implementar depois
}

void Jardineiro::resetCont() {
    contMovimentos = 0;
    contPlantar = 0;
    contColheitas = 0;
    contEntradas = 0;
}

bool Jardineiro::setPos(int l, int c) {
    if (podeMover()) {
        this->line = l;
        this->col = c;
        contMovimentos++;
        return true;
    }
    return false;

}





bool Jardineiro::podeMover() {
    return contMovimentos < Settings::Jardineiro::max_movimentos;
}

bool Jardineiro::podePlantar() {
    return contPlantar < Settings::Jardineiro::max_plantacoes;
}

bool Jardineiro::podeColher() {
    return contColheitas < Settings::Jardineiro::max_colheitas;
}

bool Jardineiro::podeEntrarSair() {
    return contEntradas < Settings::Jardineiro::max_entradas_saidas;
}

bool Jardineiro::noJardim() {
    return nojardim;
}


void Jardineiro::setNoJardim(bool estado) {
    this->nojardim = estado;
}



void Jardineiro::decrementMove() {
    contMovimentos--;
}

void Jardineiro::decrementEntradas() {
    contEntradas--;
}

void Jardineiro::decrementPlantacoes() {
    contPlantar--;
}

void Jardineiro::decrementColheitas() {
    contColheitas--;
}



void Jardineiro::incrementaPlantacoes() {
    contPlantar++;
}

void Jardineiro::incrementarEntradas() {
    contEntradas++;
}

int Jardineiro::getLine() const {
    return line;
}

int Jardineiro::getCol() const {
    return col;
}

Ferramenta* Jardineiro::getFerrameta() {
    return ferramenta;
}

std::vector<Ferramenta*>& Jardineiro::getFerramentas() {
    return ferramentas;
}

void Jardineiro::receberFerramenta(Ferramenta* f) {
    if (f != nullptr) {
        this->ferramentas.push_back(f);
        std::cout << "Jardineiro tem uma nova ferramenta"  "\n";
    }
}

void Jardineiro::incrementaMovimentos() {
    contMovimentos++;
}

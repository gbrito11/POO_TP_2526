//
// Created by gbrito11 on 19/10/2025.
//

#include "Jardineiro.h"

#include "Jardineiro.h"

#include "Settings.h"
#include "Ferranentas/Ferramenta.h"


Jardineiro::Jardineiro() : line(0), col(0), nojardim(false), ferramenta(nullptr) {

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

void Jardineiro::apanhaFerr(Celula& cell) {
    // implementar depois
}

void Jardineiro::resetCont() {
    // implementar depois
}

void Jardineiro::setPos() {
    // implementar depois
}

void Jardineiro::sai() {
    // implementar depois
}

bool Jardineiro::entra(int line, int col) {
    // implementar depois
    return false;
}

bool Jardineiro::podeMover() {
    // implementar depois
    return false;
}

bool Jardineiro::podePlantar() {
    // implementar depois
    return false;
}

bool Jardineiro::podeColher() {
    // implementar depois
    return false;
}

bool Jardineiro::podeEntrarSair() {
    // implementar depois
    return false;
}

bool Jardineiro::noJardim() {
    return nojardim;
}

void Jardineiro::decrementMove() {
    // implementar depois
}

void Jardineiro::decrementEntradas() {
    // implementar depois
}

void Jardineiro::decrementPlantacoes() {
    // implementar depois
}

void Jardineiro::decrementColheitas() {
    // implementar depois
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
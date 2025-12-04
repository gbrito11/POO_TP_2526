//
// Created by gbrito11 on 19/10/2025.
//

#include "Jardineiro.h"

#include "Jardineiro.h"

#include <algorithm>
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





//////////////////////////////////////////
///Ferramentas
///

void Jardineiro::adicionaFerr(Ferramenta* ferramenta) {
    // Verifica se a ferramenta é válida
    if (ferramenta != nullptr) {
        // Adiciona ao fim do vetor (Mochila)
        this->ferramentas.push_back(ferramenta);

         std::cout << "Ferramenta adicionada a mochila.\n";
    }
}

void Jardineiro::removeFerr(int serialNum) {
    for (auto it = ferramentas.begin(); it != ferramentas.end(); ++it) {

        if ((*it)->getSerialNum() == serialNum) {
            delete *it; // Destrói o objeto
            ferramentas.erase(it); // Re0ove do vetor
            std::cout << "Ferramenta " << serialNum << " removida.\n";
            return;
        }
    }
}

void Jardineiro::setFerr(int serialNum) {
    // 1. Se já tiver algo na mão, guarda primeiro
    if (this->ferramenta != nullptr) {
        largarMao();
    }

    // 2. Procura a ferramenta na mochila com um ciclo FOR normal
    for (auto it = ferramentas.begin(); it != ferramentas.end(); ++it) {

        // Verifica se é a ferramenta certa
        if ((*it)->getSerialNum() == serialNum) {

            // 3. Encontrou! Põe na mão
            this->ferramenta = *it;

            // 4. Remove da mochila usando o iterador
            ferramentas.erase(it);

            std::cout << "Pegaste na ferramenta " << this->ferramenta->getType()
                      << " [ID:" << serialNum << "].\n";
            return; // Sai da função, já encontraste
        }
    }

    // Se o ciclo acabar e não retornou, é porque não encontrou
    std::cout << "Nao tens nenhuma ferramenta com ID " << serialNum << " na mochila.\n";
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


void Jardineiro::largarMao() {
    if (this->ferramenta != nullptr) {
        this->ferramentas.push_back(this->ferramenta); // Devolve à mochila
        std::cout << "Guardaste o " << this->ferramenta->getType() << " na mochila.\n";
        this->ferramenta = nullptr; // Mão fica vazia
    } else {
        std::cout << "Nao tens nada na mao para largar.\n";
    }
}








////////////////////////////////////////////////////
///Contadoress
///


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

void Jardineiro::resetCont() {
    contMovimentos = 0;
    contPlantar = 0;
    contColheitas = 0;
    contEntradas = 0;
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


void Jardineiro::incrementaMovimentos() {
    contMovimentos++;
}

void Jardineiro::incrementaPlantacoes() {
    contPlantar++;
}

void Jardineiro::incrementarEntradas() {
    contEntradas++;
}
void Jardineiro::incrementaColheitas() {
    contColheitas++;
}





/////////////////////////////////////7
///oque o jardineiro pode fazer
///
///
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



int Jardineiro::getLine() const {
    return line;
}

int Jardineiro::getCol() const {
    return col;
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


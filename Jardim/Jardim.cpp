//
// Created by gbrito11 on 18/10/2025.
//

#include "Jardim.h"
#include <iostream>
#include "Celula.h"
#include "../Jardineiro.h"
#include "../Ferranentas/Ferramenta.h"
#include "../Planta/Planta.h"

Jardim::Jardim() : colunas(0), linhas(0), varIsCreated(false), jardineiro(nullptr), celulas(nullptr) {}

Jardim::~Jardim() {
    if (celulas != nullptr) {
        for (int i = 0; i < linhas; i++) {
            delete[] celulas[i];
        }
        delete[] celulas;
    }

    if (jardineiro != nullptr) {
        delete jardineiro;
    }
}
void Jardim::cria(int c, int l) {
    linhas = c;
    colunas= l;

    celulas = new Celula*[linhas];
    for (int i = 0; i < linhas; i++) {
        celulas[i] = new Celula[colunas];
    }
    // adicionar logica de colocar 3 ferramentas aleatórias em posições aleatórias
    varIsCreated = true;
    mostrar();
}

void Jardim::mostrar() {

    std::cout << "\n ";

    //print do header
    for (int c = 0; c < colunas; c++) {
        std::cout << LetraColuna(c) << ' ';
    }
    std::cout << '\n';

    for (int l = 0; l < linhas; l++) {
        // Letra da linha à esquerda em MAIÚSCULA
        std::cout << LetraLinha(l) << "  ";

        // Conteúdo de cada célula
        for (int c = 0; c < colunas; c++) {
            std::cout << MostraCelula(l, c) << ' ';
        }

        std::cout << '\n';
    }
    std::cout << '\n';


}

char Jardim::MostraCelula(int l, int c) {
    Celula& celula = celulas[l][c];

    // Prioridade: jardineiro > planta > ferramenta > espaço vazio
    if (jardineiro != nullptr && jardineiro->noJardim() &&
        jardineiro->getLine() == l && jardineiro->getCol() == c) {
        return '*';
        }

    if (celula.getPlanta() != nullptr)
        return celula.getPlanta()->getType();

    if (celula.getFerramenta() != nullptr)
        return celula.getFerramenta()->getType();

    return '.';  // Posição vazia
}


void Jardim::addPlanta(Planta* p, int x, int y) {
    celulas[x][y].setPlanta(p);
    mostrar();
}

void Jardim::addFerramenta(Ferramenta* f, int x, int y) {
    // implementar depois
}


int Jardim::getLinhas() {
    return linhas;
}
int Jardim::getColunas() {
    return colunas;
}
bool Jardim::criada() {
    return this->varIsCreated;
}

char Jardim::LetraLinha(int l) {
    return 'A' + l;  // Maiúscula para a régua
}

char Jardim::LetraColuna(int c) {
    return 'A' + c;  // Maiúscula para a régua
}

void Jardim::RandomCelula(int& x, int& y) {
    // implementar depois
}

void Jardim::limpaCelulas() {
    // implementar depois
}

Ferramenta* Jardim::RandomFerramenta() {
    // implementar depois
    return nullptr;
}



bool Jardim::PosValid(int x, int y) {
    // implementar depois
    return false;
}

Celula& Jardim::getCelula(int x, int y) {
    return celulas[x][y];
}

int Jardim::LetraNum(char letra) {
    letra = toupper(letra);
    return letra - 'A';
}




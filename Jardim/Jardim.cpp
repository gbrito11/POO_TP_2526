//
// Created by gbrito11 on 18/10/2025.
//

#include "Jardim.h"
#include <iostream>
#include "Celula.h"
#include "../Jardineiro.h"
#include "../Ferranentas/Ferramenta.h"
#include "../Ferranentas/Regador.h"
#include "../Ferranentas/Adubo.h"
#include "../Ferranentas/Tesoura.h"
#include "../Ferranentas/FerramentaZ.h"
#include "../Planta/Planta.h"
#include "../Settings.h"
#include <cstdlib>

Jardim::Jardim(int c, int l) : jardineiro(nullptr), celulas(nullptr) {
    colunas = c;
    linhas= l;


    celulas = new Celula*[linhas];
    for (int i = 0; i < linhas; i++) {
        celulas[i] = new Celula[colunas];

        for (int j = 0; j < colunas; j++) {

            // Gerar valores com rand() usando os Settings
            int aguaAleatoria = rand() % (Settings::Jardim::agua_max - Settings::Jardim::agua_min + 1)
                                + Settings::Jardim::agua_min;

            int nutrientesAleatorios = rand() % (Settings::Jardim::nutrientes_max - Settings::Jardim::nutrientes_min + 1)
                                       + Settings::Jardim::nutrientes_min;

            celulas[i][j].setAgua(aguaAleatoria);
            celulas[i][j].setNutrientes(nutrientesAleatorios);

        }
    }

    //--- 3 FERRAMENTAS ALEATÓRIAS ---
    for (int k = 0; k < 3; k++) {
        int x, y;
        RandomCelula(x, y);


        if (celulas[x][y].getFerramenta() == nullptr) {
            // Se não tiver, coloca uma ferramenta aleatória
            celulas[x][y].setFerramenta(RandomFerramenta());
        } else {
            k--;
        }
    }
    //--------------------------------------------------

    // adicionar logica de colocar 3 ferramentas aleatórias em posições aleatórias
    varIsCreated = true;
    mostrar();
}
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
    if (!varIsCreated || celulas == nullptr) {
        std::cerr << "addPlanta: garden not created\n";
        return;
    }
    if (x < 0 || x >= linhas || y < 0 || y >= colunas) {
        std::cerr << "addPlanta: invalid position (" << x << "," << y << ")\n";
        return;
    }

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
    x = rand() % linhas;
    y = rand() % colunas;
}

void Jardim::limpaCelulas() {
    // implementar depois
}

Ferramenta* Jardim::RandomFerramenta() {
    int tipo = rand() % 4; // 0, 1,2,32
    switch (tipo) {
        case 0: return new Regador();
        case 1: return new Adubo();
        case 2: return new Tesoura();
        case 3: return new Dreno();
        default: return nullptr;
    }
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




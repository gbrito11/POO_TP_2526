//
// Created by gbrito11 on 18/10/2025.
//

#include "Jardim.h"
#include <iostream>
#include "Celula.h"

Jardim::Jardim(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    mapa = new Celula*[linhas];
    for (int i = 0; i < linhas; i++) {
        mapa[i] = new Celula[colunas];
    }
}



Jardim::~Jardim() {}

void Jardim::mostrar() {
    const char letras[26] = {
        'A','B','C','D','E','F','G','H','I','J',
        'K','L','M','N','O','P','Q','R','S','T',
        'U','V','W','X','Y','Z'
    };

    std::cout << "Jardim:\n   ";

    // Cabeçalho das colunas (topo)
    for (int c = 0; c < colunas && c < 26; c++)
        std::cout << letras[c] << ' ';
    std::cout << '\n';

    // Cada linha, com régua à esquerda e à direita
    for (int l = 0; l < linhas && l < 26; l++) {
        std::cout << letras[l] << " ";  // Letra da linha à esquerda
        for (int c = 0; c < colunas && c < 26; c++) {
            std::cout << mapa[l][c].mostrar() << '.'; // Mostra conteúdo da célula
        }
        std::cout << '\n';
    }


}

Celula& Jardim::getSolo(int l, int c) {
    return mapa[l][c];
}

void Jardim::adicionarPlanta(Planta* /*p*/, int /*l*/, int /*c*/) {

}

void Jardim::adicionarFerramenta(Ferramenta* /*f*/, int /*l*/, int /*c*/) {

}






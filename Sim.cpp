//
// Created by gbrito11 on 18/10/2025.
//
#include <iostream>
#include <sstream>
#include "Sim.h"
#include "Jardim/Jardim.h"
#include "Jardineiro.h"

Sim::Sim() : jardim(), jardineiro(),emExecucao(true){}

Sim::~Sim() {
    delete jardim;
    delete jardineiro;
}

void Sim::run() {
    std::string linha;
    std::cout << "=== Simulador de Jardim ===\n";

    while (emExecucao) {
        std::cout << "> ";
        std::getline(std::cin, linha);
        processarComando(linha);
    }
}

void Sim::processarComando(const std::string& linha) {
    std::stringstream ss(linha);
    std::string cmd;
    ss >> cmd;

    if (cmd == "jardim") {
        int linhas, colunas;
        if (ss >> linhas >> colunas)
            cmdJardim(linhas, colunas);
        else
            std::cout << "Uso: jardim <linhas> <colunas>\n";

    } else if (cmd == "planta") {
        std::string pos;
        char tipo;
        if (ss >> pos >> tipo)
            cmdPlanta(pos, tipo);
        else
            std::cout << "Uso: planta <pos> <tipo>\n";

    } else if (cmd == "colhe") {
        std::string pos;
        if (ss >> pos)
            cmdColhe(pos);
        else
            std::cout << "Uso: colhe <pos>\n";

    } else if (cmd == "avanca") {
        int n = 1;
        ss >> n;
        cmdAvanca(n);

    } else if (cmd == "sai") {
        cmdSai();

    } else if (cmd == "fim") {
        cmdFim();

    } else {
        std::cout << "Comando desconhecido.\n";
    }
}

void Sim::cmdJardim(int l,int c) {
    delete jardim;
    jardim = new Jardim(l,c);
    std::cout << "Jardim criado com " << l << "x" << c << " posições.\n";
    jardim->mostrar();
}

void Sim::cmdPlanta(const std::string& pos, char tipo) {
    if (!jardim) {
        std::cout << "Erro: ainda não existe um jardim.\n";
        return;
    }
    std::cout << "Plantar tipo '" << tipo << "' na posição " << pos << ".\n";
    // adicioanr a planta
}

void Sim::cmdColhe(std::string pos) {
    std::cout << "Colher planta na posição " << pos << ".\n";
    // Aqui vais chamar jardim->colherPlanta(pos)
}

void Sim::cmdAvanca(int n) {
    std::cout << "Avançar " << n << " instantes.\n";
    // chama para avancar o tempo
}

void Sim::cmdSai() {
    std::cout << "Jardineiro saiu do jardim.\n";
    // jadrineiro sai do jardim
}

void Sim::cmdFim() {
    std::cout << "A terminar simulação...\n";
    emExecucao = false;
}

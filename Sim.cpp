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

    //comandos do jardim
    if (cmd == "jardim") {
        int linhas, colunas;
        if (ss >> linhas >> colunas)
            cmdJardim(linhas, colunas);
        else
            std::cout << "Uso: jardim <linhas> <colunas>\n";


    }
    //////////////////////////////////////
    //Relacao com plantas-----------------------
    ////////////////////////
    else if (cmd == "planta") {
        std::string pos;
        std::string tipo;

        if (ss >> pos >> tipo) {
            if (pos.size() != 2) {
                std::cout << "Uso: planta <posição> <tipo> (ex: planta FB F)\n";
            }
            else {
                char linha = pos[0];
                char coluna = pos[1];
                cmdPlanta(linha,coluna, tipo);
            }
        }
        else {
            std::cout << "Uso: planta <posição> <tipo>\n";
        }
    } else if (cmd == "colhe") {
        std::string pos;
        if (ss >> pos ) {
            if (pos.size() != 2) {
                std::cout << "Uso: Colher <posição> (ex: planta FB )\n";
            }
            else {
                char linha = pos[0];
                char coluna = pos[1];
                cmdColhe(linha,coluna);
            }
        }else
            std::cout << "Uso: colhe <pos>\n";


    }
/////////////////////////////////////////////////////////
    // COMANDOS FERRAMENTAS
////////////////////////////////////////////////////

    else if (cmd == "larga") {
        std::cout << "A largar ferramenta...\n";
        cmdLarga();
    }else if (cmd == "compra") {
        char tipo;
        ss>>tipo;
        std::cout << "A comprar ferramenta...\n";
        if(tipo== 'g' || tipo == 'a' || tipo == 't' || tipo == 'z') {
            cmdCompraFerramenta(tipo);
        }
    }
/////////////////////////////////////////////////////
///Movimentso do Jardineiro
////////////////////////////////////////
    else if (cmd == "e" || cmd== "d" || cmd == "b" || cmd == "c") {
        char mov= cmd[0];
        switch (mov) {
            case 'e':
                cmdEsquerda();
                break;
            case 'd':
                cmdDireita();
                break;
            case 'b':
                cmdBaixo();
                break;
            case 'c':
                cmdCima();
            default:
                std::cout << "MOvimento inválido!\n";
                break;

        }
    }

    else if (cmd== "entra") {
        std::string pos;
        if (ss >> pos ) {
            if (pos.size() != 2) {
                std::cout << "Uso: Entra <posição> (ex: planta FB )\n";
            }
            else {
                char linha = pos[0];
                char coluna = pos[1];
                cmdEntra(linha,coluna);
            }
        }else
            std::cout << "Uso: entra <pos>\n";

    }else if (cmd == "sai") {
        cmdSai();

    }
///////////////////////////////////////////////////////////////77
///Comandos informacao ao utilizador
///////////////////////////////////////////////////////////////
    else if (cmd == "Lplantas") {
        std::cout<<"Informação de todas as plantas no jardim:\n";
        cmdLPlantas();
    }else if (cmd == "Lplanta") {
        std::string pos;
        if (ss >> pos ) {
            if (pos.size() != 2) {
                std::cout << "Uso: Lplanta <posição> (ex: planta FB )\n";
            }
            else {
                char linha = pos[0];
                char coluna = pos[1];
                cmdLPlanta(linha,coluna);
            }
        }else {
            std::cout << "Uso: Lplanat <pos>\n";
        }
    }else if (cmd == "Larea") {
        std::cout<<"Informações sobre o jardim :\n";
        cmdLArea();
    }else if (cmd == "Lsolo") {
        std::string pos;
        int n = 0;

        if (ss >> pos) {
            char linha, coluna;

            if (pos.size() != 2) {
                std::cout << "Uso: Lsolo <posição> [<n>]\n";
                return;
            }

            linha = pos[0];
            coluna = pos[1];

            // tenta ler um número extra
            if (ss >> n) {
                cmdLSolo(linha, coluna, n);
            } else {
                cmdLSolo(linha, coluna);
            }
        }
        else {
            std::cout << "Uso: Lsolo <posição> [<n>]\n";
        }
    }else if (cmd == "Lferr") {
        std::cout<<"Ferramentas do Jardineiro:\n";
        cmdLferr();
    }



    else if (cmd == "avanca") {
        int n = 1;
        ss >> n;
        cmdAvanca(n);

    } else if (cmd == "fim") {
        cmdFim();

    }else if (cmd == "grava") {
        std::string nome;
        if (ss >> nome ) {
            std::cout << "Jogo gravado com o nome: " << nome << ".\n";
            cmdGrava(nome);
        }
    }else if (cmd == "recupera") {
        std::string nome;
        if (ss >> nome) {
            std::cout << "Jogo recuperado com o nome: " << nome << ".\n";
            cmdRecupera(nome);
        }
    }else if (cmd == "apaga") {
        std::string nome;
        if (ss >> nome) {
            std::cout << "Jogo apagado com o nome: " << nome << ".\n";
            cmdApaga(nome);
        }
    }else if (cmd == "executa") {
        std::string nome;
        if (ss >> nome) {
            std::cout << "Jogo executado com o nome: " << nome << ".\n";
            cmdExecuta(nome);
        }
    }
     else {
        std::cout << "Comando desconhecido.\n";
    }
}

void Sim::cmdJardim(int l,int c) {
    delete jardim;
    jardim = new Jardim(l,c);
    std::cout << "Jardim criado com " << l << "x" << c << " posições.\n";
    jardim->mostrar();
}


// PLantas---------------------------------------
void Sim::cmdPlanta( char l, char c , std::string tipo) {
    if (!jardim) {
        std::cout << "Erro: ainda não existe um jardim.\n";
        return;
    }
    std::cout << "Plantar tipo '" << tipo << "' na posição : <" << l <<"> <"<< c << ">" ".\n";
    // adicioanr a planta
}

void Sim::cmdColhe(char l, char c) {
    std::cout << "Colher planta na posição " << l << ","<< c << ".\n";
    // Aqui vais chamar jardim->colherPlanta(pos)
}

// Ferramentas--------------------------------------------------------
void Sim::cmdLarga() {
    std::cout << "A largar ferramenta...\n";
    // chama para largar a ferramenta
}
void Sim::cmdCompraFerramenta(char tipo) {
    std::cout << "A comprar ferramenta...\n";
    // chama para comprar a ferramenta
}

//MOvimentso do jardineiro-----------------------------
void cmdEsquerda() {
    //esquerda
}
void cmdDireita() {
    //direita
}
void cmdCima() {
    //cima
}
void cmdBaixo() {
    //baixo
}

void cmdEntra(char l,char c) {
    std::cout<<"Jardineiro vai entrar na posição <"<<l<<"> <"<< c<<">" << std::endl;
    //implementar o jardineiro a esntrar
}

void cmdSai() {
    std::cout<<"Jardineiro a sair do jardim..."<<std::endl;
}

//Comandos informacao ao utilizador------------------------------------------------------

void Sim::cmdLPlantas() {
    std::cout << "Informação de todas as plantas no jardim.\n";
    // listar todas as plantas
}
void Sim::cmdLPlanta(char l,char c) {
    std::cout << "Informação da planta na posição " << l << "," << c << ".\n";
    // mostrar info da planta na posicao
}
void Sim::cmdLArea() {
    std::cout << "Informação da área do jardim.\n";
}

void Sim::cmdLSolo(char l, char c) {
    // código para 1 célula
}

void Sim::cmdLSolo(char l, char c, int n) {
    // código para n células
}

void Sim::cmdLferr() {
    std::cout << "Informação da ferramenta do jardineiro.\n";
    // mostrar info da ferramenta
}
//COmados especificos-------------------------------------------
void Sim::cmdAvanca(int n) {
    std::cout << "Avançar " << n << " instantes.\n";
    // chama para avancar o tempo
}

void Sim::cmdFim() {
    std::cout << "A terminar simulação...\n";
    emExecucao = false;
}


void Sim::cmdGrava(std::string jogo){
    std::cout<<"A gravar jogo..."<<std::endl;
    //GRavar o jogo
}

void Sim::cmdRecupera(std::string jogo) {
    std::cout<<"A recuperar jogo..."<<std::endl;
    //REcuperar o jogo
}

void Sim::cmdApaga(std::string jogo) {
    std::cout<<"A apagar jogo..."<<std::endl;
    //Apagar o jogo
}

void Sim::cmdExecuta(std::string comandos) {
    std::cout<<"A executar comandos..."<<std::endl;
    //executa comandos de um ficheiro para uo jogo
}
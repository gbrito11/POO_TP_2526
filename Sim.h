#ifndef SIM_H
#define SIM_H

#include <string>
#include "Jardim/Jardim.h"
#include "Jardineiro.h"
class Jardim;
class Jardineiro;


class Sim {
private:
    Jardim* jardim = nullptr;
    Jardineiro* jardineiro = nullptr;
    bool emExecucao = true;
    int instantes;

public:
    Sim();
    ~Sim();

    void run();                // loop principal
    void processarComando(const std::string& linha);

    // comandos Jardim/PLantas
    void cmdJardim(int l,int c);
    void cmdPlanta( char l,char c, std::string tipo);
    void cmdColhe(char l, char c);

    //COmandos ferramentas
    void cmdLarga();
    void cmdCompraFerramenta(char tipo);
    void cmdPega(int n);

    //Moviemtos
    void cmdEsquerda();
    void cmdDireita();
    void cmdCima();
    void cmdBaixo();
    void cmdEntra(char l,char c);
    void cmdSai();

    //Comandos de Informacao ao utilizador
    void cmdLPlantas();
    void cmdLPlanta(char l,char c);
    void cmdLArea();
    void cmdLSolo(char l,char c);
    void cmdLSolo(char l, char c, int n);
    void cmdLferr();
    void cmdInfo();

    //Comandos diversos
    void cmdAvanca(int n);
    void cmdFim();
    void cmdGrava(std::string jogo);
    void cmdRecupera(std::string jogo);
    void cmdApaga(std::string jogo);
    void cmdExecuta(std::string comandos);
};

#endif

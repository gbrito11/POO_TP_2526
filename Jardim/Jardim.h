// Created by gbrito11 on 18/10/2025.//

#ifndef TP_JARDIM_H
#define TP_JARDIM_H

#include "Celula.h"
#include <string>

class Ferramenta;
class Jardineiro;
class Planta;
class Settings;
class Jardim {
public:
    Jardim(int l, int c);

    ~Jardim();

    bool entra(int l,int c);  //feito
    bool moverJardineiro(int i);
    void addPlanta(int l, int c,std::string tipo); //feito
    void gerarNovaFerramenta();

    void avanca(int n);

    void addFerramenta(Ferramenta* f, int l, int c); //feito
    void RandomCelula(int& x, int& y); //feito
    void limpaCelulas();
    char LetraLinha(int line);
    char LetraColuna(int column);
    char MostraCelula(int x, int y);
    Ferramenta* RandomFerramenta(); //feito
    void mostrar(); //feito
    bool criada();
    bool PosValid(int x, int y); //feito
    int getLinhas(); //feito
    int getColunas(); //feito
    int LetraNum(char l);//feito

    Celula& getCelula(int x, int y);


private:
    Celula **celulas;
    int linhas, colunas;
    Jardineiro* jardineiro;
    bool varIsCreated;



};


#endif //TP_JARDIM_H
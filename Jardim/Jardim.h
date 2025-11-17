// Created by gbrito11 on 18/10/2025.//

#ifndef TP_JARDIM_H
#define TP_JARDIM_H

#include "Celula.h"

class Ferramenta;
class Jardineiro;
class Planta;
class Settings;
class Jardim {
public:
    Jardim(int l, int c);

    ~Jardim();


    void addPlanta(Planta* p, int l, int c);
    void addFerramenta(Ferramenta* f, int l, int c);
    void RandomCelula(int& x, int& y);
    void limpaCelulas();
    char LetraLinha(int line);
    char LetraColuna(int column);
    char MostraCelula(int x, int y);
    Ferramenta* RandomFerramenta();
    void mostrar();
    bool criada();
    bool PosValid(int x, int y);
    int getLinhas();
    int getColunas();
    int LetraNum(char l);

    Celula& getCelula(int x, int y);


private:
    Celula **celulas;
    int linhas, colunas;
    Jardineiro* jardineiro;
    bool varIsCreated;



};


#endif //TP_JARDIM_H
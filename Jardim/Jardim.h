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
    void addFerramenta(Ferramenta* f, int l, int c); //feito
    Ferramenta* RandomFerramenta(); //feito
    void gerarNovaFerramenta();
    void jardineiroPegaFerramenta(int id);
    void jardineiroLargaFerramenta();
    void jardineiroCompraFerramenta(char tipo);
    void listarFerramentasJardineiro();


    void addPlanta(int l, int c,std::string tipo); //feito
    void colhePlanta(int l, int c);

    void avanca(int n);


    void RandomCelula(int& x, int& y); //feito
    void limpaCelulas();
    char LetraLinha(int line);
    char LetraColuna(int column);
    char MostraCelula(int x, int y);

    void mostrar(); //feito
    bool criada();
    bool PosValid(int x, int y); //feito
    int getLinhas(); //feito
    int getColunas(); //feito
    int LetraNum(char l);//feito

    Celula& getCelula(int x, int y);
    int getInstantes();

    void listArea();
    void inspectSolo(int l,int c);


private:
    int instantes;
    Celula **celulas;
    int linhas, colunas;
    Jardineiro* jardineiro;
    bool varIsCreated;



};


#endif //TP_JARDIM_H
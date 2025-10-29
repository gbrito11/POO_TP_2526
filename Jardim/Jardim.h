// Created by gbrito11 on 18/10/2025.//

#ifndef TP_JARDIM_H
#define TP_JARDIM_H

#include "Celula.h"

class Ferramenta;
class Jardineiro;
class Planta;

class Jardim {
public:
    explicit Jardim(int linhas, int colunas);
    ~Jardim();

    void mostrar();

    Celula& getSolo(int l, int c);

    void adicionarPlanta(Planta* p, int l, int c);

    void adicionarFerramenta(Ferramenta* f, int l, int c);
    Celula **mapa;

private:

    int linhas, colunas;

    Jardineiro* jardineiro;
};


#endif //TP_JARDIM_H
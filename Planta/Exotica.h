//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_PLANTAEXÓTICA_H
#define TP_PLANTAEXÓTICA_H
#include "Planta.h"

class Exotica : public Planta {
public:
    Exotica();
    ~Exotica() override;

    void processaTempo(Celula& celula) override;
    void multiplica(Celula& celula) override;
    void efeitoMorte(Celula& celula) override;
    bool deveMorrer() override;

    void takeAgua() override;
    void takeNutrientes() override;

    void darAgua() override;
    void darNutrientes() override;
};

//a cada 3 instantes vai fazer chover, adiciona mais 10 de agua a todas plantas

#endif //TP_PLANTAEXÓTICA_H
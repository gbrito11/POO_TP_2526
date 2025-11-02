//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_ROSEIRA_H
#define TP_ROSEIRA_H
#include "Planta.h"
#include "../Settings.h"

class Roseira : public Planta {
public:
    Roseira();
    ~Roseira() override;

    void time() override;
    void multiplica() override;
    bool deveMorrer() override;

    void takeAgua() override;
    void takeNutrientes() override;

    void darAgua() override;
    void darNutrientes() override;
};


#endif //TP_ROSEIRA_H
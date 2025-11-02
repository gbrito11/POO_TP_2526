//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_ERVADANINHA_H
#define TP_ERVADANINHA_H
#include "Planta.h"
#include "../Settings.h"

class ErvaDaninha : public Planta {

protected:
    int timeNascimento;

public:
    ErvaDaninha();
    ~ErvaDaninha() override;

    void time() override;
    void multiplica() override;
    bool deveMorrer() override;

    void takeAgua() override;
    void takeNutrientes() override;

    void darAgua() override;
    void darNutrientes() override;

};


#endif //TP_ERVADANINHA_H
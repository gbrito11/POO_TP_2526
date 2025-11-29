//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_CACTO_H
#define TP_CACTO_H
#include "Planta.h"

class Cacto : public Planta {
public:
    Cacto();
    ~Cacto() override;


    void processaTempo(Celula &celula) override;
    bool querMultiplicar() override;
    Planta* reproduz() override;
    void efeitoMorte(Celula& celula) override;
    bool deveMorrer() override;

    void takeAgua() override;
    void takeNutrientes() override;

    void darAgua() override;
    void darNutrientes() override;
};


#endif //TP_CACTO_H
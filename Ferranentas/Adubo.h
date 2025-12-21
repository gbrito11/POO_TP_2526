//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_PACOTEADUBO_H
#define TP_PACOTEADUBO_H
#include "Ferramenta.h"
#include "../Settings.h"
class Celula;
// Classe Adubo que usa os valores definidos em Settings::Adubo
class Adubo : public Ferramenta {
public:
    Adubo();
    ~Adubo() override;

    void usa(Celula& cell) override;
    bool vazio() override;
    std::string Info() override;



};


#endif //TP_PACOTEADUBO_H
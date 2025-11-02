//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_TESOURA_H
#define TP_TESOURA_H
#include "Ferramenta.h"
class Celula;
class Tesoura  : public Ferramenta {
public:
    Tesoura();
    ~Tesoura() override;

    void usa(Celula& cell) override;
    bool vazio() override; // nunca vai estar, é infinita
    std::string Info() override;
};


#endif //TP_TESOURA_H
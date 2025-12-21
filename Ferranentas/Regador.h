//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_REGADOR_H
#define TP_REGADOR_H
#include "Ferramenta.h"
#include "../Settings.h"

class Celula;
class Regador : public Ferramenta {

public:
    Regador();
    ~Regador() override;

    void usa(Celula& cell) override;
    bool vazio() override;
    std::string Info() override;


};


#endif //TP_REGADOR_H
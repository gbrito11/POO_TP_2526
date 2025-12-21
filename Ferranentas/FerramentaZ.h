//
// Created by gbrito11 on 02/11/2025.
//

#ifndef TP_FERRAMENTAZ_H
#define TP_FERRAMENTAZ_H
#include "Ferramenta.h"


class Dreno : public Ferramenta {
    static const int CAPACIDADE_INICIAL = 100;
    static const int DOSE_DRENAGEM = 50;
    public:
    Dreno();
    ~Dreno() override;

    void usa(Celula& cell) override;
    bool vazio() override;
    std::string Info() override;


    //Vai matar as ervas daninhas
};

#endif //TP_FERRAMENTAZ_H
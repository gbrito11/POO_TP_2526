//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_FERRAMENTA_H
#define TP_FERRAMENTA_H
#include <string>


class Celula;
class Ferramenta {

protected:
    int serialNum;
    static int nextSerialNum; // contador global para o numero de serie
    int capacidade;
    char type;

public:
    Ferramenta();
    virtual ~Ferramenta();

    virtual void usa(Celula& cell) = 0;  // comportamento ao usar
    virtual bool vazio() = 0;  // verificar se está gasta
    virtual std::string Info() = 0;  // info para comando lferr

    int getCapacidade();
    void setCapacidade(int c);
    int getSerialNum();
    void setSerialNum(int s);


    char getType();
};


#endif //TP_FERRAMENTA_H
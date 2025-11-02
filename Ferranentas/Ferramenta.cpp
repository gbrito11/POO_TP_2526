//
// Created by gbrito11 on 19/10/2025.
//

#include "Ferramenta.h"
int Ferramenta::nextSerialNum = 1;

Ferramenta::Ferramenta() {
    serialNum = nextSerialNum++;
    type = ' ';
}

Ferramenta::~Ferramenta() {
    // logica para remover tool dps
}

int Ferramenta::getSerialNum() {
    return serialNum;
}

char Ferramenta::getType() {
    return type;
}
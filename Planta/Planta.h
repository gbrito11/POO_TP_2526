//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_PLANTA_H
#define TP_PLANTA_H
#include <string>

class Celula;
class Settings;

class Planta {
    public:

    Planta(std::string beauty);
    virtual ~Planta();

    char getType();
    std::string getBeauty();



    virtual void processaTempo(Celula& celula) = 0;
    virtual void efeitoMorte(Celula& celula) = 0;
    virtual bool querMultiplicar() = 0;

    virtual Planta* reproduz() = 0;

    virtual bool deveMorrer() = 0;

    virtual void takeAgua() = 0;
    virtual void takeNutrientes() = 0;

    virtual void darAgua() = 0;
    virtual void darNutrientes() = 0;

    bool Viva();

    int getAgua();
    int getNutrientes();
    int getIdade();



protected:
    int agua;
    int nutrientes;
    int idade;
    std::string beauty;
    int timeSemAgua;
    int timeExtraAgua;
    int timeSemNutrientes;
    bool viva;
    char type;


};


#endif //TP_PLANTA_H
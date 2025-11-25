//
// Created by gbrito11 on 18/10/2025.
//

#ifndef TP_CELULA_H
#define TP_CELULA_H
class Planta;
class Ferramenta;
class Jardineiro;

class Celula {
public:

    Celula();
    ~Celula();
    char mostrar() const;
    char getCharVisivel(const Jardineiro* jardineiro) const;

    int getAgua(); //
    int getNutrientes(); //
    Planta* getPlanta(); //
    Ferramenta* getFerramenta(); //

    void setAgua(int agua);
    void setNutrientes(int nutrientes);
    void setPlanta(Planta* planta);
    void removePlanta();
    void setFerramenta(Ferramenta* ferramenta);

    Ferramenta* largarFerramenta();

private:
    int agua = 0;
    int nutrientes = 0;
    Planta* planta = nullptr;
    Ferramenta* ferramenta = nullptr;
    char type = ' ';

};


#endif //TP_CELULA_H
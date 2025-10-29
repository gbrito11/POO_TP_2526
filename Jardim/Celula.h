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
    Celula(char c);
    Celula();
    char mostrar() const;
    char getCharVisivel(const Jardineiro* jardineiro) const;
    void alterarAgua(int delta);
    void alterarNutrientes(int delta);

private:
    int agua = 0;
    int nutrientes = 0;
    Planta* planta = nullptr;
    Ferramenta* ferramenta = nullptr;
    char conteudo = ' ';
};


#endif //TP_CELULA_H
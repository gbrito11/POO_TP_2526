//
// Created by gbrito11 on 19/10/2025.
//

#ifndef TP_JARDINEIRO_H
#define TP_JARDINEIRO_H
#include <vector>
class Ferramenta;
class Celula;
class Jardineiro {
private:
    int line, col;
    bool nojardim;

    std::vector<Ferramenta*> ferramentas;
    Ferramenta* ferramenta;

    // contador para usar no limite de açoes por turno
    int contMovimentos;
    int contPlantar;
    int contColheitas;
    int contEntradas;
public:
    Jardineiro();
    ~Jardineiro();

    void adicionaFerr(Ferramenta* tool);
    void removeFerr(int serialNum);
    void setFerr(int serialNum);
    void apanhaFerr(Celula& cell);

    void resetCont();

    void setPos(); // auxiliar

    void sai();
    bool entra(int l, int c);
    bool podeMover();
    bool podePlantar();
    bool podeColher();
    bool podeEntrarSair();
    bool noJardim();


    int getMaxMove();
    int getMaxEntradas();
    int getMaxPlantacoes();
    int getMaxColheitas();

    void decrementMove();
    void decrementEntradas();
    void decrementPlantacoes();
    void decrementColheitas();

    int getLine() const;
    int getCol() const;

    Ferramenta* getFerrameta();
    std::vector<Ferramenta*>& getFerramentas();
};


#endif //TP_JARDINEIRO_H
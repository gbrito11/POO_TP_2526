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
    void receberFerramenta(Ferramenta* f);
    void largarMao();
    bool temFerramenta(char tipo);


    void resetCont();

    bool setPos(int l, int c); // auxiliar

    bool podeMover();//feito
    bool podePlantar();//feito
    bool podeColher();//feito
    bool podeEntrarSair();//feito
    bool noJardim();//feito
    void setNoJardim(bool estado); //feito


    int getMaxMove();
    int getMaxEntradas();
    int getMaxPlantacoes();
    int getMaxColheitas();

    void decrementMove();
    void decrementEntradas();
    void decrementPlantacoes();
    void decrementColheitas();

    void incrementaPlantacoes();
    void incrementarEntradas(); //feito
    void incrementaColheitas();
    void incrementaMovimentos(); //feito

    int getLine() const;
    int getCol() const;

    Ferramenta* getFerrameta();
    std::vector<Ferramenta*>& getFerramentas();
};


#endif //TP_JARDINEIRO_H
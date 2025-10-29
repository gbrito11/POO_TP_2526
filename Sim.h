#ifndef SIM_H
#define SIM_H

#include <string>
#include "Jardim/Jardim.h"
#include "Jardineiro.h"
class Jardim;
class Jardineiro;


class Sim {
private:
    Jardim* jardim = nullptr;
    Jardineiro* jardineiro = nullptr;
    bool emExecucao = true;

public:
    Sim();
    ~Sim();

    void run();                // loop principal
    void processarComando(const std::string& linha);

    // comandos específicos
    void cmdJardim(int l,int c);
    void cmdPlanta(const std::string& pos, char tipo);
    void cmdColhe(std::string pos);
    void cmdAvanca(int n);
    void cmdSai();
    void cmdFim();
};

#endif

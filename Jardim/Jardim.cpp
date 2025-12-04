//
// Created by gbrito11 on 18/10/2025.
//

#include "Jardim.h"
#include <iostream>
#include "Celula.h"
#include "../Jardineiro.h"
#include "../Ferranentas/Ferramenta.h"
#include "../Ferranentas/Regador.h"
#include "../Ferranentas/Adubo.h"
#include "../Ferranentas/Tesoura.h"
#include "../Ferranentas/FerramentaZ.h"
#include "../Planta/Planta.h"
#include "../Settings.h"
#include "../Planta/Roseira.h"
#include "../Planta/Cacto.h"
#include "../Planta/ErvaDaninha.h"
#include "../Planta/Exotica.h"
#include <cstdlib>


Jardim::Jardim(int c, int l) : jardineiro(nullptr), celulas(nullptr) {
    colunas = c;
    linhas= l;
    instantes=1;
    jardineiro = new Jardineiro();


    celulas = new Celula*[linhas];
    for (int i = 0; i < linhas; i++) {
        celulas[i] = new Celula[colunas];

        for (int j = 0; j < colunas; j++) {

            // Gerar valores com rand() usando os Settings
            int aguaAleatoria = rand() % (Settings::Jardim::agua_max - Settings::Jardim::agua_min + 1)
                                + Settings::Jardim::agua_min;

            int nutrientesAleatorios = rand() % (Settings::Jardim::nutrientes_max - Settings::Jardim::nutrientes_min + 1)
                                       + Settings::Jardim::nutrientes_min;

            celulas[i][j].setAgua(aguaAleatoria);
            celulas[i][j].setNutrientes(nutrientesAleatorios);

        }
    }

    //--- 3 FERRAMENTAS ALEATÓRIAS ---
    for (int k = 0; k < 3; k++) {
        int x, y;
        RandomCelula(x, y);


        if (celulas[x][y].getFerramenta() == nullptr) {
            // Se não tiver, coloca uma ferramenta aleatória
            celulas[x][y].setFerramenta(RandomFerramenta());
        } else {
            k--;
        }
    }
    //--------------------------------------------------

    // adicionar logica de colocar 3 ferramentas aleatórias em posições aleatórias
    varIsCreated = true;
    mostrar();
}
Jardim::~Jardim() {
    if (celulas != nullptr) {
        for (int i = 0; i < linhas; i++) {
            delete[] celulas[i];
        }
        delete[] celulas;
    }

    if (jardineiro != nullptr) {
        delete jardineiro;
    }
}


   void Jardim::mostrar() {

    std::cout << "\n ";

    //print do header
    for (int c = 0; c < colunas; c++) {
        std::cout << LetraColuna(c) << ' ';
    }
    std::cout << '\n';

    for (int l = 0; l < linhas; l++) {
        // Letra da linha à esquerda em MAIÚSCULA
        std::cout << LetraLinha(l) << "  ";

        // Conteúdo de cada célula
        for (int c = 0; c < colunas; c++) {
            std::cout << MostraCelula(l, c) << ' ';
        }

        std::cout << '\n';
    }
    std::cout << '\n';


}

char Jardim::MostraCelula(int l, int c) {
    Celula& celula = celulas[l][c];

    // Prioridade: jardineiro > planta > ferramenta > espaço vazio
    if (jardineiro != nullptr && jardineiro->noJardim() &&
        jardineiro->getLine() == l && jardineiro->getCol() == c) {
        return '*';
        }

    if (celula.getPlanta() != nullptr)
        return celula.getPlanta()->getType();

    if (celula.getFerramenta() != nullptr)
        return celula.getFerramenta()->getType();

    return '.';  // Posição vazia
}

////////////////////////////////////////
///  Plantas
///
void Jardim::addPlanta(int x, int y,std::string tipo) {
    // 1. O Guarda-Portão PEDE PERMISSÃO
    if (!jardineiro->podePlantar()) {
        std::cout << "O Jardineiro ja plantou o maximo ("
                  << jardineiro->getMaxPlantacoes() << ") por turno.\n";
        return;
    }

    // 2. O Guarda-Portão VALIDA A POSIÇÃO
    if (!PosValid(x, y)) {
        std::cout << "Erro: Posicao (" << x << "," << y << ") invalida.\n";
        return;
    }

    if (celulas[x][y].getPlanta() != nullptr) {
        std::cout << "Erro: Ja existe uma planta nessa posicao.\n";
        return;
    }

    // 4. LÓGICA DE CRIAÇÃO (O que estava em Sim.cpp)
    Planta* p = nullptr;
    if (tipo == "r" || tipo == "roseira") {
        p = new Roseira();
    } else if (tipo == "c" || tipo == "cacto") {
        p = new Cacto();
    } else if (tipo == "e" || tipo == "erva") {
        p = new ErvaDaninha();
    } else if (tipo == "x" || tipo == "exotica") {
        p = new Exotica();
    } else {
        std::cout << "Erro: Tipo de planta '" << tipo << "' desconhecido.\n";
        return; // Não faz nada se o tipo for inválido
    }

    // 5. O Guarda-Portão DÁ AS ORDENS
    celulas[x][y].setPlanta(p);
    jardineiro->incrementaPlantacoes(); // <-- Faz a incrementação aqui!
    mostrar();
}



void Jardim::addFerramenta(Ferramenta* f, int x, int y) {
    // implementar depois
}


int Jardim::getLinhas() {
    return linhas;
}
int Jardim::getColunas() {
    return colunas;
}
bool Jardim::criada() {
    return this->varIsCreated;
}

char Jardim::LetraLinha(int l) {
    return 'A' + l;  // Maiúscula para a régua
}

char Jardim::LetraColuna(int c) {
    return 'A' + c;  // Maiúscula para a régua
}

void Jardim::RandomCelula(int& x, int& y) {
    x = rand() % linhas;
    y = rand() % colunas;
}

void Jardim::limpaCelulas() {
    // implementar depois
}

Ferramenta* Jardim::RandomFerramenta() {
    int tipo = rand() % 4; // 0, 1,2,32
    switch (tipo) {
        case 0: return new Regador();
        case 1: return new Adubo();
        case 2: return new Tesoura();
        case 3: return new Dreno();
        default: return nullptr;
    }
    return nullptr;
}



bool Jardim::PosValid(int x, int y) {
    return (x >= 0 && x < linhas && y >= 0 && y < colunas);
}

Celula& Jardim::getCelula(int x, int y) {
    return celulas[x][y];
}

int Jardim::LetraNum(char letra) {
    letra = toupper(letra);
    return letra - 'A';
}


///////////////////////////////
///------------------------- JARDINEIRO
/////////////////////////

void Jardim::jardineiroPegaFerramenta(int id) {
    if (jardineiro != nullptr) {
        jardineiro->setFerr(id);
    } else {
        std::cout << "Jardineiro nao existe.\n";
    }
}

void Jardim::jardineiroLargaFerramenta() {
    if (jardineiro != nullptr) {
        jardineiro->largarMao();
    } else {
        std::cout << "Jardineiro nao existe.\n";
    }
}

void Jardim::jardineiroCompraFerramenta(char tipo) {
    if (jardineiro == nullptr) return;

    Ferramenta* f = nullptr;
    if (tipo == 'g') f = new Regador();
    else if (tipo == 'a') f = new Adubo();
    else if (tipo == 't') f = new Tesoura();
    else if (tipo == 'z') f = new Dreno();
    else {
        std::cout << "Ferramenta desconhecida.\n";
        return;
    }

    jardineiro->adicionaFerr(f);
    std::cout << "Ferramenta comprada!\n";
}

void Jardim::listarFerramentasJardineiro() {
    if (jardineiro == nullptr) return;

    std::vector<Ferramenta*>& mochila = jardineiro->getFerramentas();

    std::cout << "=== Mochila ===\n";
    if (mochila.empty()) std::cout << "(Vazia)\n";
    else {
        for (Ferramenta* f : mochila) {
            std::cout << f->Info() << "\n";
        }
    }

    Ferramenta* mao = jardineiro->getFerrameta();
    std::cout << "=== Mao ===\n";
    if (mao) std::cout << mao->Info() << "\n";
    else std::cout << "(Vazia)\n";
}


bool Jardim::entra(int l,int c) {
    // 2. O Jardim verifica a permissão
    if (!this->jardineiro->podeEntrarSair()) {
        std::cout << "O Jardineiro ja nao pode entrar/sair neste turno.\n";
        return false;
    }

    if (PosValid(l, c)) {
        jardineiro->setPos(l, c);
        jardineiro->incrementarEntradas();
        this->jardineiro->setNoJardim(true);

        // --- LÓGICA DE APANHAR FERRAMENTA (CONTROLADA PELO JARDIM) ---
        if (celulas[l][c].getFerramenta() != nullptr) {

            // 1. O JARDIM tira a ferramenta da célula (sem destruir)
            Ferramenta* f = celulas[l][c].largarFerramenta();

            // 2. O JARDIM entrega ao jardineiro
            jardineiro->receberFerramenta(f);

            std::cout << "O jardineiro encontrou uma ferramenta: " << f->getType() << "\n";

            // 3. O JARDIM faz a magia
            gerarNovaFerramenta();
        }
        // -----------------------------------------------------------
    }

    std::cout << "Jardineiro entrou no jardim.\n";
    return true;
}

void Jardim::gerarNovaFerramenta() {
    int x, y;
    int tentativas = 0;
    do {
        RandomCelula(x, y);
        tentativas++;
    } while (celulas[x][y].getFerramenta() != nullptr && tentativas < 1000);

    if (celulas[x][y].getFerramenta() == nullptr) {
        celulas[x][y].setFerramenta(RandomFerramenta());
        std::cout << "Magia! Uma nova ferramenta apareceu.\n";
    }
}


bool Jardim::moverJardineiro(int direcao) {
    // 1. Verificações Iniciais
    if (jardineiro == nullptr || !jardineiro->noJardim()) {
        std::cout << "Jardineiro nao esta no jardim.\n";
        return false;
    }

    if (!jardineiro->podeMover()) {
        std::cout << "Jardineiro esta cansado, ja se moveu "
                  << jardineiro->getMaxMove() << " vezes.\n";
        return false;
    }

    // 2. Calcular nova posição baseada no switch
    int l = jardineiro->getLine();
    int c = jardineiro->getCol();

    switch (direcao) {
        case 0: l--; break; // Cima (diminui linha)
        case 1: l++; break; // Baixo (aumenta linha)
        case 2: c++; break; // Direita (aumenta coluna)
        case 3: c--; break; // Esquerda (diminui coluna)
        default:
            std::cout << "Direcao invalida.\n";
            return false;
    }

    // 3. Validar e Executar
    if (PosValid(l, c)) {
        // Mover o jardineiro
        jardineiro->setPos(l, c);
        jardineiro->incrementaMovimentos();

        // --- APANHAR FERRAMENTA
        if (celulas[l][c].getFerramenta() != nullptr) {
            Ferramenta* f = celulas[l][c].largarFerramenta();
            jardineiro->receberFerramenta(f);
            std::cout << "O jardineiro encontrou uma ferramenta: " << f->getType() << "\n";


            int nx, ny;
            do {
                RandomCelula(nx, ny);
            } while (celulas[nx][ny].getFerramenta() != nullptr); // Procura vazia
            celulas[nx][ny].setFerramenta(RandomFerramenta());
            std::cout << "Magia! Uma nova ferramenta apareceu.\n";
        }
        // --------------------------

        mostrar(); // Atualizar o ecrã
        return true;
    } else {
        std::cout << "Nao pode mover-se para fora do jardim.\n";
        return false;
    }
}


void setJardineiro(Jardineiro* j, int l, int c) {

}


void Jardim::colhePlanta(int l, int c) {
    // 1. Verificar se o Jardineiro existe
    if (jardineiro == nullptr) {
        std::cout << "Erro: Jardineiro nao existe.\n";
        return;
    }

    // 2. O Guarda-Portão PEDE PERMISSÃO (Limite de 5 por turno)
    if (!jardineiro->podeColher()) {
        std::cout << "O Jardineiro ja colheu o maximo ("
                  << jardineiro->getMaxColheitas() << ") plantas neste turno.\n";
        return;
    }

    // 3. O Guarda-Portão VALIDA A POSIÇÃO
    if (!PosValid(l, c)) {
        std::cout << "Erro: Posicao invalida.\n";
        return;
    }

    // 4. O Guarda-Portão VERIFICA SE HÁ PLANTA
    if (celulas[l][c].getPlanta() == nullptr) {
        std::cout << "Erro: Nao ha nenhuma planta nessa posicao para colher.\n";
        return;
    }

    // 5. EXECUÇÃO (Apanhar a planta)
    Planta* p = celulas[l][c].getPlanta();
    std::cout << "O Jardineiro colheu uma " << p->getType() << " (Idade: " << p->getIdade() << ").\n";

    // Remove a planta da memória e da célula
    celulas[l][c].removePlanta();

    // 6. ATUALIZAR O ESTADO (Jardineiro cansa-se)
    jardineiro->incrementaColheitas();

    mostrar(); // Atualiza o ecrã
}

/////////////////////////////77
/// Tempo
///////////////////////////

void Jardim::avanca(int n) {
    // Arrays auxiliares para ver os vizinhos (Cima, Baixo, Esq, Dir)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int k = 0; k < n; k++) {
        // Opcional: Mostrar em que instante estamos
        std::cout << "--- Instante " << (instantes) << " ---\n";
        instantes++;
        Ferramenta* f = jardineiro->getFerrameta(); // (Nota: tens um typo no nome, é 'getFerrameta')
        if (jardineiro != nullptr && jardineiro->noJardim()) {
            if (f != nullptr) {
                int l = jardineiro->getLine();
                int c = jardineiro->getCol();

                // Avisa o utilizador
                std::cout << "[Jardineiro] A usar " << f->getType()
                      << " na posicao " << LetraLinha(l) << LetraColuna(c) << "...\n";

                // USA A FERRAMENTA NA CÉLULA ATUAL
                f->usa(celulas[l][c]);

                // Verifica se a ferramenta se gastou/partiu
                if (f->vazio()) {
                    std::cout << "A ferramenta " << f->getType() << " acabou/partiu-se!\n";

                    // Remove da mão (tens de ter implementado o largarMao ou similar que anule o ponteiro)
                    // Como o 'vazio()' é true, podes simplesmente anulá-la ou removê-la da mochila.
                    // Uma forma simples agora:
                    jardineiro->largarMao(); // Guarda na mochila (vazia)
                    jardineiro->removeFerr(f->getSerialNum()); // Remove permanentemente da mochila
                }
            }
        }
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {

                // Obtém a planta (se existir)
                Planta* p = celulas[i][j].getPlanta();

                if (p != nullptr) {

                    int chuva = p->getChuva(); // Para a planta exotica, faz chuver 20 em cada solo

                    if (chuva > 0 && instantes % 5 == 0) {
                        std::cout << "A Exotica fez chover " << chuva << " de agua em todo o jardim!\n";

                        // O Jardim percorre a grelha TODA para dar água
                        for (int r = 0; r < linhas; r++) {
                            for (int c = 0; c < colunas; c++) {
                                int aguaAtual = celulas[r][c].getAgua();
                                // Limita ao máximo de 100 se quiseres, ou deixa subir infinito
                                int novaAgua = aguaAtual + chuva;
                                if (novaAgua > Settings::Jardim::agua_max) novaAgua = Settings::Jardim::agua_max;

                                celulas[r][c].setAgua(novaAgua);
                            }
                        }
                    }

                    // 1. PRIMEIRO: A planta vive o turno
                    // (Aqui é que os contadores 'timeExtraAgua' aumentam!)
                    p->processaTempo(celulas[i][j]);

                    // 2. SEGUNDO: Verifica se deve morrer AGORA
                    if (p->deveMorrer()) {
                        std::cout << "Planta " << p->getType() << " morreu na posicao "
                                  << LetraLinha(i) << LetraColuna(j) << ".\n";

                        // Deixa os nutrientes no solo
                        p->efeitoMorte(celulas[i][j]);

                        // Remove-a fisicamente da memória e da célula
                        celulas[i][j].removePlanta();

                        // Se morreu, não faz mais nada com ela neste turno
                        continue;
                    }

                    // 3. TERCEIRO: Se sobreviveu, tenta multiplicar
                    if (p->querMultiplicar()) {

                        // Lógica da Erva Daninha (Mata vizinhos)
                        if (p->getType() == 'e') {
                             for (int v = 0; v < 4; v++) {
                                int ni = i + dx[v];
                                int nj = j + dy[v];
                                if (PosValid(ni, nj)) {
                                    // Mata quem lá estiver
                                    if (celulas[ni][nj].getPlanta() != nullptr) {
                                        celulas[ni][nj].removePlanta();
                                    }
                                    celulas[ni][nj].setPlanta(p->reproduz());
                                    break;
                                }
                             }
                        }
                        // Lógica das outras (Só em vazio)
                        else {
                            for (int v = 0; v < 4; v++) {
                                int ni = i + dx[v];
                                int nj = j + dy[v];
                                if (PosValid(ni, nj) && celulas[ni][nj].getPlanta() == nullptr) {
                                    celulas[ni][nj].setPlanta(p->reproduz());
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (jardineiro != nullptr) {
        // O tempo passou, por isso o jardineiro recupera a os contadores para o próximo turno
        jardineiro->resetCont();
    }
    // Só mostra o jardim no fim de todos os instantes
    mostrar();
}


///////////////////////
///Comandos SOLO
////////

void Jardim::inspectSolo(int l, int c) {
    if (!PosValid(l, c)) {
        return; // Ignora posições inválidas (útil para o loop do raio)
    }

    Celula& cell = celulas[l][c];

    // Só mostra o cabeçalho se a função for chamada isoladamente,
    // mas para listas grandes queremos algo compacto.
    // Vamos fazer um formato limpo:
    std::cout << "| Pos: " << LetraLinha(l) << LetraColuna(c) << " | "
              << "Agua: " << cell.getAgua() << " | "
              << "Nutri: " << cell.getNutrientes() << " | ";

    // Informação da Planta
    if (cell.getPlanta() != nullptr) {
        Planta* p = cell.getPlanta();
        std::cout << "Planta: " << p->getType()
                  << " (Idade:" << p->getIdade()
                  << " A:" << p->getAgua()
                  << " N:" << p->getNutrientes() << ") ";
    }

    // Informação da Ferramenta
    if (cell.getFerramenta() != nullptr) {
        std::cout << "Ferramenta: " << cell.getFerramenta()->getType() << " ";
    }

    // Jardineiro
    if (jardineiro != nullptr && jardineiro->noJardim() &&
        jardineiro->getLine() == l && jardineiro->getCol() == c) {
        std::cout << "[JARDINEIRO]";
        }

    std::cout << "\n";
}

void Jardim::listArea() {
    std::cout << "=== Area Ocupada do Jardim ===\n";
    bool vazio = true;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Critério para "não totalmente vazia": Tem Planta OU Tem Ferramenta
            // (Opcional: Podes incluir também se tiver o Jardineiro)
            bool temCoisa = (celulas[i][j].getPlanta() != nullptr ||
                             celulas[i][j].getFerramenta() != nullptr);

            if (temCoisa) {
                inspectSolo(i, j); // Reutiliza a função de inspeção
                vazio = false;
            }
        }
    }

    if (vazio) {
        std::cout << "O jardim esta vazio de objetos.\n";
    }
}
cmake_minimum_required(VERSION 4.0)
project(TP)

set(CMAKE_CXX_STANDARD 20)

add_executable(TP main.cpp
        Jardim/Jardim.cpp
        Jardim/Jardim.h
        Jardim/Celula.cpp
        Jardim/Celula.h
        Sim.cpp
        Sim.h
        Jardineiro.cpp
        Jardineiro.h
        Ferranentas/Regador.cpp
        Ferranentas/Regador.h
        Ferranentas/Adubo.cpp
        Ferranentas/Adubo.h
        Ferranentas/Tesoura.cpp
        Ferranentas/Tesoura.h
        Ferranentas/Ferramenta.cpp
        Ferranentas/Ferramenta.h
        Planta/Cacto.cpp
        Planta/Cacto.h
        Planta/Roseira.cpp
        Planta/Roseira.h
        Planta/ErvaDaninha.cpp
        Planta/ErvaDaninha.h
        Planta/Exotica.cpp
        Planta/Exotica.h
        Planta/Planta.cpp
        Planta/Planta.h
        Ferranentas/FerramentaZ.cpp
        Ferranentas/FerramentaZ.h
        Settings.h

)

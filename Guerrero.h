#pragma once

#include "Unidad.h"
#include <string>

class Guerrero : public Unidad
{
private:
    std::string arma;
    int armadura;
    int costoMana;      

public:

    Guerrero();
    Guerrero(std::string nombre,
              int vida,
              int mana,
              int ataque,
              int nivel,
              std::string arma,
              int armadura);

    // Getters
    std::string getArma() const;
    int getArmadura() const;

    // Setters
    void setArma(std::string arma);
    void setArmadura(int armadura);

    // Métodos propios
    void seleccionarArma();      

    // Métodos sobrescritos
    int calculaAtaque(const Unidad& objetivo) const override;
    void recibeAtaque(int ptosAtaque) override;
    void imprimir() const override;
    void atacar(Unidad& objetivo) override;   // <-- FALTABA
};
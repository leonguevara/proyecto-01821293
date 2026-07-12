#pragma once

#include "Unidad.h"
#include <string>

class Arquero : public Unidad
{
private:
    int precision;
    bool flechaEnvenenada;

public:

    Arquero();

    Arquero(std::string nombre,
             int vida,
             int mana,
             int ataque,
             int nivel,
             int precision);

    // Getters
    int getPrecision() const;

    // Setters
    void setPrecision(int precision);

    // Método propio
    void seleccionarFlecha();

    // Métodos sobrescritos
    int calculaAtaque(const Unidad& objetivo) const override;
    void atacar(Unidad& objetivo) override;
    void imprimir() const override;
};
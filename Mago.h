#pragma once

#include "Unidad.h"
#include <string>

class Mago : public Unidad
{
private:
    int poderMagico;

public:

    // Constructores
    Mago();

    Mago(std::string nombre,
          int vida,
          int mana,
          int ataque,
          int nivel,
          int poderMagico);

    // Getters
    int getPoderMagico() const;

    // Setters
    void setPoderMagico(int poderMagico);

    // Método propio
    void seleccionarHechizo();

    // Métodos sobrescritos
    int calculaAtaque(const Unidad& objetivo) const override;
    void atacar(Unidad& objetivo) override;
    void imprimir() const override;
};
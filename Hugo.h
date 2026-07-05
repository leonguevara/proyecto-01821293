#pragma once

class Unidad
{
private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:

    // Constructores
    Unidad();
    Unidad(int vida, int ataque, int nivel);

    // Getters
    int getVida() const;
    int getSalud() const;
    int getAtaque() const;
    int getNivel() const;

    // Setters
    void setVida(int vida);
    void setSalud(int salud);
    void setAtaque(int ataque);
    void setNivel(int nivel);

    // Métodos
    int porcentajeSalud() const;
    void imprimeBarra() const;
    int calculaAtaque(Unidad &objetivo);
    void recibeAtaque(int ptosAtaque);
    void atacar(const Unidad &objetivo) const;
    void imprimir() const;
};
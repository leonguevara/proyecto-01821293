#pragma once
#include <string>

class Unidad
{
private:
    std::string nombre;

    int vida;
    int salud;
    int ataque;
    int nivel;

public:

    Unidad();
    Unidad(std::string nombre, int vida, int ataque, int nivel);

    // Getters
    std::string getNombre() const;
    int getVida() const;
    int getSalud() const;
    int getAtaque() const;
    int getNivel() const;

    // Setters
    void setNombre(std::string nombre);
    void setVida(int vida);
    void setSalud(int salud);
    void setAtaque(int ataque);
    void setNivel(int nivel);

    // Métodos
    int porcentajeSalud() const;
    void imprimeBarra() const;
    int calculaAtaque(const Unidad &objetivo) const;
    void recibeAtaque(int ptosAtaque);
    void atacar(Unidad &objetivo);
    bool estaVivo() const;
    void imprimir() const;
};
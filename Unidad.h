#pragma once
#include <string>

class Unidad
{
protected:
    std::string nombre;

    int vida;
    int salud;
    int mana;
    int ataque;
    int nivel;

public:

    Unidad();
    Unidad(std::string nombre, int vida, int mana, int ataque, int nivel);

    virtual ~Unidad() = default;

    // Getters
    std::string getNombre() const;
    int getVida() const;
    int getSalud() const;
    int getMana() const;
    int getAtaque() const;
    int getNivel() const;

    // Setters
    void setVida(int vida);
    void setSalud(int salud);
    void setMana(int mana);
    void setAtaque(int ataque);
    void setNivel(int nivel);

    bool estaVivo() const;

    //Metodos de ataque y defensa
    virtual int calculaAtaque(const Unidad& objetivo) const;
    virtual void recibeAtaque(int ptosAtaque);
    virtual void imprimir() const;

    virtual void atacar(Unidad& objetivo);

    int porcentajeSalud() const;
    void imprimeBarra() const;
};
#include "Unidad.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor por defecto
Unidad::Unidad()
{
    vida = 100;
    salud = 100;
    ataque = 20;
    nivel = 1;
}

// Constructor con parámetros
Unidad::Unidad(int vida, int ataque, int nivel)
{
    this->vida = vida;
    salud = vida;
    this->ataque = ataque;
    this->nivel = nivel;
}

// Getters
int Unidad::getVida() const
{
    return vida;
}

int Unidad::getSalud()
{
    return salud;
}

int Unidad::getAtaque()
{
    return ataque;
}

int Unidad::getNivel()
{
    return nivel;
}

// Setters
void Unidad::setVida(int vida)
{
    this->vida = vida;

    if(salud > vida)
        salud = vida;
}

void Unidad::setSalud(int salud)
{
    this->salud = salud;
}

void Unidad::setAtaque(int ataque)
{
    this->ataque = ataque;
}

void Unidad::setNivel(int nivel)
{
    this->nivel = nivel;
}

// Calcula el porcentaje de salud
int Unidad::porcentajeSalud()
{
    if(vida == 0)
        return 0;

    return (salud * 100) / vida;
}

// Imprime barra de vida
void Unidad::imprimeBarra()
{
    int porcentaje = porcentajeSalud();
    int llenos = porcentaje / 5;

    cout << "[";

    for(int i = 0; i < llenos; i++)
        cout << "%";

    for(int i = llenos; i < 20; i++)
        cout << "-";

    cout << "] " << porcentaje << "%" << endl;
}

// Calcula ataque
int Unidad::calculaAtaque(Unidad &objetivo)
{
    if(objetivo.getNivel() > nivel)
    {
        return rand() % (ataque / 2) + 1;
    }
    else
    {
        return rand() % (ataque - ataque / 2 + 1) + ataque / 2;
    }
}

// Descuenta vida
void Unidad::recibeAtaque(int ptosAtaque)
{
    salud -= ptosAtaque;

    if(salud < 0)
        salud = 0;
}

// Atacar
void Unidad::atacar(Unidad &objetivo)
{
    int dano = calculaAtaque(objetivo);

    cout << "Ataque de " << dano << " puntos." << endl;

    objetivo.recibeAtaque(dano);
}

// Imprimir datos
void Unidad::imprimir()
{
    cout << "Vida maxima: " << vida << endl;
    cout << "Salud actual: " << salud << endl;
    cout << "Ataque: " << ataque << endl;
    cout << "Nivel: " << nivel << endl;

    imprimeBarra();

    cout << endl;
}
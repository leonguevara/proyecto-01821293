#include "Unidad.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor por defecto
Unidad::Unidad()
{
   nombre = "Unidad";

   vida = 100;
    salud = 100;
    mana = 100;
    ataque = 10;
    nivel = 1;
}

// Constructor con parámetros
Unidad::Unidad(std::string nombre, int vida, int mana, int ataque, int nivel)
{
    this->nombre = nombre;

    this->vida = vida;
    salud = vida;

    this->mana = mana;

    this->ataque = ataque; 
    this->nivel = nivel;
}

// Getters
string Unidad::getNombre() const

{
    return nombre;
}


int Unidad::getVida() const{
    return vida;
}

int Unidad::getSalud() const
{
    return salud;
}

int Unidad::getAtaque() const
{
    return ataque;
}

int Unidad::getNivel() const
{
    return nivel;
}
int Unidad::getMana() const
{
    return mana;
}
// Setters
void Unidad::setVida(int vida)
{
    this->vida = vida;

    if (salud > vida)
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

void Unidad::setMana(int mana)
{
    this->mana = mana;
}
// Calcula el porcentaje de salud
int Unidad::porcentajeSalud() const
{
    if (vida == 0)
        return 0;

    return (salud * 100) / vida;
}

// Imprime barra de vida
void Unidad::imprimeBarra() const
{
    int porcentaje = porcentajeSalud();
    int llenos = porcentaje / 5;

    cout << "[";

    for (int i = 0; i < llenos; i++)
        cout << "%";

    for (int i = llenos; i < 20; i++)
        cout << "-";

    cout << "] " << porcentaje << "%" << endl;
}

// Calcula ataque
int Unidad::calculaAtaque(const Unidad &objetivo) const
{
    if (objetivo.getNivel() > nivel)
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

    if (salud < 0)
        salud = 0;
}

// Atacar
void Unidad::atacar(Unidad &objetivo)
{
    int dano = calculaAtaque(objetivo);

    cout << "Ataque de " << dano << " puntos." << endl;

    objetivo.recibeAtaque(dano);
}

// Verifica si sigue vivo
bool Unidad::estaVivo() const
{
    return salud > 0;
}

// Imprimir datos
void Unidad::imprimir() const
{
    cout << "=============/=============" << endl;

    cout << "Nombre: " << nombre << endl;
    cout << "Vida maxima: " << vida << endl;
    cout << "Salud actual: " << salud << endl;
    cout << "Mana: " << mana << endl;
    cout << "Ataque: " << ataque << endl;
    cout << "Nivel: " << nivel << endl;

    imprimeBarra();

    cout << "=============/=============" << endl;
    cout << endl;
}
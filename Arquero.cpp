#include "Arquero.h"
#include <iostream>

using namespace std;

// Constructor por defecto
Arquero::Arquero()
    : Unidad("Arquero", 90, 80, 20, 1)
{
    precision = 80;
    flechaEnvenenada = false;
}

// Constructor con parámetros
Arquero::Arquero(string nombre,
                 int vida,
                 int mana,
                 int ataque,
                 int nivel,
                 int precision)
    : Unidad(nombre, vida, mana, ataque, nivel)
{
    this->precision = precision;
    flechaEnvenenada = false;
}

// Getter
int Arquero::getPrecision() const
{
    return precision;
}

// Setter
void Arquero::setPrecision(int precision)
{
    this->precision = precision;
}

// Seleccionar flecha
void Arquero::seleccionarFlecha()
{
    int opcion;

    cout << "\n===== ARQUERO =====" << endl;
    cout << "1. Flecha normal (+10 daño)" << endl;
    cout << "2. Preparar flecha envenenada (+25 daño siguiente turno)" << endl;

    cout << "\nSelecciona una opcion: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 2)
    {
        cout << "Opcion invalida. Intenta de nuevo: ";
        cin >> opcion;
    }

    if(opcion == 1)
    {
        flechaEnvenenada = false;
    }
    else
    {
        flechaEnvenenada = true;
    }
}

// Calcular ataque
int Arquero::calculaAtaque(const Unidad &objetivo) const
{
    (void)objetivo;

    if(flechaEnvenenada)
        return ataque + 25;

    return ataque + 10;
}

// Atacar
void Arquero::atacar(Unidad &objetivo)
{
    seleccionarFlecha();

    if(flechaEnvenenada)
    {
        cout << "\nEl arquero prepara una flecha envenenada..." << endl;
        cout << "Este turno no ataca.\n" << endl;

        flechaEnvenenada = false;
        return;
    }

    cout << "\n" << nombre << " dispara una flecha." << endl;

    int dano = calculaAtaque(objetivo);

    cout << "Daño realizado: " << dano << endl;

    objetivo.recibeAtaque(dano);
}

// Imprimir
void Arquero::imprimir() const
{
    Unidad::imprimir();

    cout << "Clase: Arquero" << endl;
    cout << "Precision: " << precision << endl;

    cout << "==========================" << endl;
    cout << endl;
}
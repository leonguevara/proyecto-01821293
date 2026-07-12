#include "Guerrero.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor por defecto
Guerrero::Guerrero()
    : Unidad("Guerrero", 120, 60, 25, 1)
{
    arma = "Espada corta";
    armadura = 10;
    costoMana = 0;
}

// Constructor con parámetros
Guerrero::Guerrero(string nombre,
                   int vida,
                   int mana,
                   int ataque,
                   int nivel,
                   string arma,
                   int armadura)
    : Unidad(nombre, vida, mana, ataque, nivel)
{
    this->arma = arma;
    this->armadura = armadura;
    costoMana = 0;
}

//getters
string Guerrero::getArma() const
{
    return arma;
}

int Guerrero::getArmadura() const
{
    return armadura;
}

//setters
void Guerrero::setArma(string arma)
{
    this->arma = arma;
}

void Guerrero::setArmadura(int armadura)
{
    this->armadura = armadura;
}

//Armas 
void Guerrero::seleccionarArma()
{
    int opcion;

    cout << "\n===== ARSENAL =====" << endl;
    cout << "1. Espada corta    (+5 daño)   Mana: 0" << endl;
    cout << "2. Espada larga    (+10 daño)  Mana: 5" << endl;
    cout << "3. Hacha de guerra (+18 daño)  Mana: 10" << endl;
    cout << "4. Excalibur       (+35 daño)  Mana: 20" << endl;

    cout << "\nSelecciona un arma: ";
    cin >> opcion;

    // Validar la opción
    while(opcion < 1 || opcion > 4)
    {
        cout << "Opción inválida. Intenta de nuevo: ";
        cin >> opcion;
    }

    switch(opcion)
    {
        case 1:
            arma = "Espada corta";
            costoMana = 0;
            break;

        case 2:
            arma = "Espada larga";
            costoMana = 5;
            break;

        case 3:
            arma = "Hacha de guerra";
            costoMana = 10;
            break;

        case 4:
            arma = "Excalibur";
            costoMana = 20;
            break;
    }
}
//calcula ataque
int Guerrero::calculaAtaque(const Unidad &objetivo) const
{
    if(arma == "Espada corta")
        return ataque + 5;

    if(arma == "Espada larga")
        return ataque + 10;

    if(arma == "Hacha de guerra")
        return ataque + 18;

    return ataque + 30;
}

//ataque
void Guerrero::atacar(Unidad &objetivo)
{
    seleccionarArma();

    if(mana < costoMana)
    {
        cout << "\nNo tienes suficiente mana para usar "
             << arma << "." << endl;

        cout << "Se utilizara Espada corta.\n";

        arma = "Espada corta";
        costoMana = 0;
    }

    mana -= costoMana;

    cout << "\n" << nombre << " usa " << arma << endl;
    cout << "Mana restante: " << mana << endl;

    int dano = calculaAtaque(objetivo);

    cout << "Daño realizado: " << dano << endl;

    objetivo.recibeAtaque(dano);
}
//recibe ataque
void Guerrero::recibeAtaque(int ptosAtaque)
{
    ptosAtaque -= armadura;

    if(ptosAtaque < 1)
        ptosAtaque = 1;

    Unidad::recibeAtaque(ptosAtaque);
}

//imprimir
void Guerrero::imprimir() const
{
    Unidad::imprimir();

    cout << "Clase: Guerrero" << endl;
    cout << "Arma equipada: " << arma << endl;
    cout << "Armadura: " << armadura << endl;

    cout << "==========================" << endl;
    cout << endl;
}
#include "Mago.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor que tiene por defecto 1.
Mago::Mago()
    : Unidad("Mago", 80, 120, 15, 1)
{
    poderMagico = 40;
}

// Constructor con los parámetros que se le pasan.
Mago::Mago(string nombre,
           int vida,
           int mana,
           int ataque,
           int nivel,
           int poderMagico)
    : Unidad(nombre, vida, mana, ataque, nivel)
{
    this->poderMagico = poderMagico;
}

// Getter
int Mago::getPoderMagico() const
{
    return poderMagico;
}

// Setter
void Mago::setPoderMagico(int poderMagico)
{
    this->poderMagico = poderMagico;
}

//seleccion de hechizos (lo mas pesado )
void Mago::seleccionarHechizo()
{
    cout << "\n========= MAGO =/========" << endl;
    cout << "1. Ataque Magico algo generico" << endl;
    cout << "2. Bola de Fuego" << endl;  //clasico de D&D
    cout << "3. Rayo" << endl; //otro clasico de D&D
    cout << "4. Sacrilegus" << endl; // hechizo que copie del smash

}

//calcular los ataques del mago
int Mago::calculaAtaque(const Unidad &objetivo) const
{
    (void)objetivo;

    return ataque + poderMagico;
}

//Ataques del mago (como estuvo largo esto)
void Mago::atacar(Unidad &objetivo)
{
    int opcion;

    seleccionarHechizo();

    cout << "\nSelecciona un hechizo: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 4)
    {
        cout << "Opcion invalida: ";
        cin >> opcion;
    }

    switch(opcion)
    {
        case 1:
        {
            cout << "\nAtaque Magico\n";

            int dano = ataque + poderMagico;

            objetivo.recibeAtaque(dano);

            cout << "Daño: " << dano << endl;

            break;
        }

        case 2:
        {
            cout << "\n¡¡Bola de Fuego!!\n";

            if(mana >= 10)
            {
                mana -= 10;

                int dano = ataque + poderMagico + 15;

                objetivo.recibeAtaque(dano);

                cout << "Daño: " << dano << endl;
            }
            else
            {
                cout << "No tienes suficiente mana." << endl;
            }

            break;
        }

        case 3:
        {
            cout << "\n⚡ Rayo ⚡\n";

            if(mana >= 15)
            {
                mana -= 15;

                int dano = ataque + poderMagico + 10;

                objetivo.recibeAtaque(dano);

                cout << "El enemigo queda aturdido." << endl;
                cout << "Daño: " << dano << endl;
            }
            else
            {
                cout << "No tienes suficiente mana." << endl;
            }

            break;
        }

        case 4:
        {
            cout << "\n========== SACRILEGUS ==========\n";

            if(mana < 30)
            {
                cout << "Mana insuficiente." << endl;
                break;
            }

            mana -= 30;

            int destino = rand() % 100;

            if(destino < 70)
            {
                cout << "¡¡Sacrilegus destruye al enemigo!!" << endl;

                objetivo.recibeAtaque(9999);
            }
            else
            {
                cout << "¡¡Sacrilegus consume al mago!!" << endl;

                recibeAtaque(9999);
            }

            break;
        }
    }
}

void Mago::imprimir() const
{
    Unidad::imprimir();

    cout << "Clase: Mago" << endl;
    cout << "Poder Magico: " << poderMagico << endl;

    cout << "==========================" << endl;
    cout << endl;
}
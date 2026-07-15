#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Unidad.h"
#include "Guerrero.h"
#include "Arquero.h"
#include "Mago.h"

using namespace std;

int main2()
{
    srand(time(nullptr));

    // Crear personajes
    Guerrero guerrero("Haaland", 120, 60, 25, 2, "Espada corta", 10);
    Arquero arquero("Hawkeye", 90, 80, 20, 2, 85);
    Mago mago("Hermenejildo", 80, 120, 15, 2, 40);

    cout << "======================================" << endl;
    cout << "      PERSONAJES DEL JUEGO" << endl;
    cout << "======================================" << endl;

    guerrero.imprimir();
    arquero.imprimir();
    mago.imprimir();

    cout << "\n======================================" << endl;
    cout << "        COMIENZA LA BATALLA" << endl;
    cout << "======================================\n" << endl;

    // Guerrero ataca al Mago
    cout << "\n===== TURNO DEL GUERRERO =====" << endl;
    guerrero.atacar(mago);

    cout << "\nEstado del Mago:\n";
    mago.imprimir();

    // Mago ataca al Arquero
    cout << "\n===== TURNO DEL MAGO =====" << endl;
    mago.atacar(arquero);

    cout << "\nEstado del Arquero:\n";
    arquero.imprimir();

    // Arquero ataca al Guerrero
    cout << "\n===== TURNO DEL ARQUERO =====" << endl;
    arquero.atacar(guerrero);

    cout << "\nEstado del Guerrero:\n";
    guerrero.imprimir();

    cout << "\n======================================" << endl;
    cout << "         FIN DE LA DEMOSTRACION" << endl;
    cout << "======================================" << endl;

    return 0;
}
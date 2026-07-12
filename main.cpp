#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Unidad.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    Unidad guerrero(100, 25, 2);
    Unidad orco(120, 20, 3);

    cout << "=== Estado inicial ===" << endl;

    cout << "\nGuerrero" << endl;
    guerrero.imprimir();

    cout << "Orco" << endl;
    orco.imprimir();

    cout << "\n=== COMIENZA LA BATALLA ===\n" << endl;

     while (guerrero.estaVivo() && orco.estaVivo())
    {
        cout << "El guerrero ataca al orco." << endl;
        guerrero.atacar(orco);

        cout << "\nEstado del orco:" << endl;
        orco.imprimir();

        if (orco.getSalud() == 0)
            break;

        cout << "El orco ataca al guerrero." << endl;
        orco.atacar(guerrero);

        cout << "\nEstado del guerrero:" << endl;
        guerrero.imprimir();
    }

    cout << "=== FIN DE LA BATALLA ===" << endl;

    if (guerrero.estaVivo() > 0)
        cout << "¡El guerrero ha ganado!" << endl;
    else
        cout << "¡El orco ha ganado!" << endl;

    return 0;
}
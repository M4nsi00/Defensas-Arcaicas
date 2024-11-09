#include "Mapa.h"
#include "Torre.h"
#include "Enemigo.h"

int main() {
    // Crear enemigos y torres
    Enemigo enemigo1(100, 1.0, 2, 3);
    Enemigo enemigo2(50, 1.5, 5, 5);

    Torre torre1(20, 4, 50, 0, 0);
    Torre torre2(15, 6, 40, 3, 3);

    // Crear el mapa
    Mapa mapa;

    // Usar los setters para agregar torres y enemigos
    mapa.setEnemigo(enemigo1);
    mapa.setEnemigo(enemigo2);
    mapa.setTorre(torre1);
    mapa.setTorre(torre2);

    // Imprimir el mapa antes de atacar
    mapa.imprimirMapa();

    // Hacer que las torres ataquen
    mapa.ataqueTorre();

    return 0;
}

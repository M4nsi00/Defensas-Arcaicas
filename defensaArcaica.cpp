#include "Mapa.h"
#include "Congelador.h"
#include "Explosiva.h"
#include "Tanque.h"
#include "Espectro.h"

int main() {
    // Crear instancias de torres y enemigos
    Torre* torre1 = new Congelador(5, 10, 50, 20, 100, 0, 0);
    Torre* torre2 = new Explosiva(30.0, 3.0, 60, 15, 150, 2, 2);

    Enemigo* enemigo1 = new Tanque(50, 100, 1, 10, 10);
    Enemigo* enemigo2 = new Espectro(50, 100, 1, 12, 12);

    // Crear el mapa
    Mapa mapa;

    // Agregar las torres y enemigos al mapa
    mapa.agregarTorre(torre1);
    mapa.agregarTorre(torre2);
    mapa.agregarEnemigo(enemigo1);
    mapa.agregarEnemigo(enemigo2);

    // Imprimir el estado inicial del mapa
    mapa.imprimirMapa();

    // Realizar ataques
    mapa.ataqueTorre();

    // Imprimir el estado final del mapa
    mapa.imprimirMapa();

    return 0;
}


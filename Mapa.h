#ifndef MAPA_H
#define MAPA_H

#include "Torre.h"
#include "Enemigo.h"
#include <vector>
#include <iostream>

using namespace std;

class Mapa {
private:
    vector<Torre*> torres;     // Lista de punteros a Torres
    vector<Enemigo*> enemigos; // Lista de punteros a Enemigos

public:
    // Agregar torres y enemigos
    void agregarTorre(Torre* torre) {
        torres.push_back(torre);
    }

    void agregarEnemigo(Enemigo* enemigo) {
        enemigos.push_back(enemigo);
    }

    // Imprimir el estado del mapa
    void imprimirMapa() const {
        cout << "---- Torres ----" << endl;
        for (size_t i = 0; i < torres.size(); ++i) {
            torres[i]->imprimeDatos(); // Llama a imprimeDatos de Torre
        }

        cout << "---- Enemigos ----" << endl;
        for (size_t i = 0; i < enemigos.size(); ++i) {
            cout << "Vida del enemigo: " << enemigos[i]->get_vida() << endl;
        }
    }

    // Hacer que las torres ataquen a los enemigos
    void ataqueTorre() {
        for (size_t i = 0; i < torres.size(); ++i) {
            for (size_t j = 0; j < enemigos.size(); ++j) {
                torres[i]->atacar(*enemigos[j]); // Ataca al enemigo
                if (enemigos[j]->get_vida() <= 0) {
                    cout << "Enemigo eliminado.\n";
                }
            }
        }

        // Eliminar enemigos con vida <= 0
        for (size_t i = 0; i < enemigos.size(); /* No incrementamos aquí */) {
            if (enemigos[i]->get_vida() <= 0) {
                delete enemigos[i];                  // Libera memoria del enemigo eliminado
                enemigos.erase(enemigos.begin() + i); // Borra el puntero del vector
            } else {
                ++i; // Incrementa solo si no se borró nada
            }
        }
    }

    // Destructor para limpiar memoria
    ~Mapa() {
        for (size_t i = 0; i < torres.size(); ++i) {
            delete torres[i]; // Libera memoria de las torres
        }

        for (size_t i = 0; i < enemigos.size(); ++i) {
            delete enemigos[i]; // Libera memoria de los enemigos
        }
    }
};

#endif



#ifndef MAPA_H
#define MAPA_H
#include "Torre.h"
#include "Enemigo.h"
#include <iostream>
#include <vector>

class Mapa {
private:
    std::vector<Torre> torres;
    std::vector<Enemigo> enemigos;

public:
    // Getters
    const std::vector<Torre>& getTorres() const {
        return torres;
    }

    const std::vector<Enemigo>& getEnemigos() const {
        return enemigos;
    }

    // Setters
    void setTorre(const Torre& _torre) {
        torres.push_back(_torre);
    }

    void setEnemigo(const Enemigo& _enemigo) {
        enemigos.push_back(_enemigo);
    }

    // Métodos
    // Imprimir el mapa	
	void imprimirMapa() const {
    std::cout << "---- Torre ----" << std::endl;
    for (size_t i = 0; i < torres.size(); ++i) {
        torres[i].imprimeDatos();
    }
    std::cout << "---- Enemigo ----" << std::endl;
    for (size_t i = 0; i < enemigos.size(); ++i) {
        enemigos[i].imprimeDatos();
    }
	}

// Hacer que la Torre ataque
void ataqueTorre() {
    for (size_t i = 0; i < torres.size(); ++i) {
        for (size_t j = 0; j < enemigos.size(); ++j) {
            torres[i].atacar(enemigos[j]);
        	}
    	}
	}
};

#endif


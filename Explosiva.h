#ifndef EXPLOSIVA_H
#define EXPLOSIVA_H

#include "Torre.h"
#include "Enemigo.h"
#include <vector>
#include <cmath>
#include <iostream>

class Explosiva : public Torre {
private:
    float danoArea;   // Daño infligido en el área
    float rangoDano;  // Rango del daño en área

public:
    // Constructor por defecto
    Explosiva() : Torre(), danoArea(0), rangoDano(0) {}

    // Constructor parametrizado
    Explosiva(float _danoArea, float _rangoDano, float _dano, float _alcance, int _coste, float _posicion_x, float _posicion_y)
        : Torre(_dano, _alcance, _coste, _posicion_x, _posicion_y),
          danoArea(_danoArea), rangoDano(_rangoDano) {}

    // Método de ataque en área
    void ataqueArea(std::vector<Enemigo>& enemigos, Enemigo& objetivo) {
        float distanciaObjetivo = sqrt(
            pow(posicion.first - objetivo.getPosicion().first, 2) +
            pow(posicion.second - objetivo.getPosicion().second, 2)
        );

        if (distanciaObjetivo <= alcance) {
            // Daño al objetivo principal
            objetivo.set_vida(objetivo.getVida() - dano);

            std::cout << "Enemigo principal atacado! Vida restante: " << objetivo.getVida() << std::endl;

            // Daño en área a otros enemigos
            for (size_t i = 0; i < enemigos.size(); ++i) {
    		Enemigo& enemigo = enemigos[i];  // Obtenemos una referencia al enemigo actual
    		float distanciaEnemigo = sqrt(pow(objetivo.getPosicion().first - enemigo.getPosicion().first, 2) + pow(objetivo.getPosicion().second - enemigo.getPosicion().second, 2));
   			if (&enemigo != &objetivo && distanciaEnemigo <= rangoDano) {
        	enemigo.set_vida(enemigo.getVida() - danoArea);
        	std::cout << "Enemigo en área atacado! Vida restante: " << enemigo.getVida() << std::endl;
    	}
	}
        } else {
            std::cout << "El enemigo está fuera del alcance de la torre explosiva." << std::endl;
        }
	}

    // Método para imprimir información específica de la torre
    void imprimeDatos() const {
    	std::cout << "---- Torre explosiva ----" << std::endl;
        Torre::imprimeDatos();
        std::cout << "Dano en area: " << danoArea << ", Rango de dano: " << rangoDano << std::endl;
    }
};

#endif

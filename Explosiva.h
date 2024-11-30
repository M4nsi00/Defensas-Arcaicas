#ifndef EXPLOSIVA_H
#define EXPLOSIVA_H

#include "Torre.h"
#include "Enemigo.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Explosiva : public Torre {
private:
    float dano_area;   // Daño infligido en el área
    float rango_dano;  // Rango del daño en área

public:
    // Constructor por defecto
    Explosiva(){
    	dano_area = 0.0;
    	rango_dano = 0.0;
	}

    // Constructor personalizado
    Explosiva(float _dano_area, float _rango_dano, float _dano, float _alcance, int _coste, float _posicion_x, float _posicion_y): Torre(_dano, _alcance, _coste, _posicion_x, _posicion_y){
    	dano_area = _dano_area;
		rango_dano = _rango_dano; 
		}
		
    // Método de ataque en área
    void ataqueArea(std::vector<Enemigo>& enemigos, Enemigo& objetivo) {
        float distanciaObjetivo = sqrt(
            pow(posicion.first - objetivo.get_posicion().first, 2) + pow(posicion.second - objetivo.get_posicion().second, 2)
        );

        if (distanciaObjetivo <= alcance) {
            // Daño al enemigo que esta en alcance
            objetivo.set_vida(objetivo.get_vida() - dano);
            cout << "Enemigo principal atacado! Vida restante: " << objetivo.get_vida() << endl;

            // Daño en área a otros enemigos esta función busca a enemigos cercanos si le da a uno pasa por un ciclo en base al rango de la explosion si hay un enemigo dentro de ese ragno tambien se le hace daño
            for (size_t i = 0; i < enemigos.size(); ++i) {
    		Enemigo& enemigo = enemigos[i];  // Obtenemos una referencia al enemigo actual
    		float distanciaEnemigo = sqrt(pow(objetivo.get_posicion().first - enemigo.get_posicion().first, 2) + pow(objetivo.get_posicion().second - enemigo.get_posicion().second, 2));
   			if (&enemigo != &objetivo && distanciaEnemigo <= rango_dano) {
        	enemigo.set_vida(enemigo.get_vida() - dano_area);
        	cout << "Enemigo en área atacado! Vida restante: " << enemigo.get_vida() << endl;
    		}
	}
        } else {
            cout << "El enemigo está fuera del alcance de la torre explosiva." << endl;
        }
	}

    // Método para imprimir datos
    void imprimeDatos() const {
    	cout << "---- Torre explosiva ----" << endl;
        Torre::imprimeDatos();
        cout << "Dano en area: " << dano_area << ", Rango de dano: " << rango_dano << endl;
    }
};

#endif

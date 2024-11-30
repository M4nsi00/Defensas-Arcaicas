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
    float dano_area;   // Da�o infligido en el �rea
    float rango_dano;  // Rango del da�o en �rea

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
		
    // M�todo de ataque en �rea
    void ataqueArea(std::vector<Enemigo>& enemigos, Enemigo& objetivo) {
        float distanciaObjetivo = sqrt(
            pow(posicion.first - objetivo.get_posicion().first, 2) + pow(posicion.second - objetivo.get_posicion().second, 2)
        );

        if (distanciaObjetivo <= alcance) {
            // Da�o al enemigo que esta en alcance
            objetivo.set_vida(objetivo.get_vida() - dano);
            cout << "Enemigo principal atacado! Vida restante: " << objetivo.get_vida() << endl;

            // Da�o en �rea a otros enemigos esta funci�n busca a enemigos cercanos si le da a uno pasa por un ciclo en base al rango de la explosion si hay un enemigo dentro de ese ragno tambien se le hace da�o
            for (size_t i = 0; i < enemigos.size(); ++i) {
    		Enemigo& enemigo = enemigos[i];  // Obtenemos una referencia al enemigo actual
    		float distanciaEnemigo = sqrt(pow(objetivo.get_posicion().first - enemigo.get_posicion().first, 2) + pow(objetivo.get_posicion().second - enemigo.get_posicion().second, 2));
   			if (&enemigo != &objetivo && distanciaEnemigo <= rango_dano) {
        	enemigo.set_vida(enemigo.get_vida() - dano_area);
        	cout << "Enemigo en �rea atacado! Vida restante: " << enemigo.get_vida() << endl;
    		}
	}
        } else {
            cout << "El enemigo est� fuera del alcance de la torre explosiva." << endl;
        }
	}

    // M�todo para imprimir datos
    void imprimeDatos() const {
    	cout << "---- Torre explosiva ----" << endl;
        Torre::imprimeDatos();
        cout << "Dano en area: " << dano_area << ", Rango de dano: " << rango_dano << endl;
    }
};

#endif

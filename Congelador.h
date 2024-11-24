#ifndef CONGELADOR_H
#define CONGELADOR_H

#include "Torre.h"
#include "Enemigo.h"
#include "Mapa.h"
#include <iostream>
#include <cmath>

using namespace std;

class Congelador : public Torre{
	private:
		int realentizar;
		int tiempo;
		
	public:
		//Constructor
		Congelador(){
			realentizar = 0;
			tiempo = 0;
		}
		
		Congelador(int _realentizar, int _tiempo, float _dano, float _alcance, int _coste, float _posicion_x, float _posicion_y) : Torre( _dano,  _alcance,  _coste,  _posicion_x,  _posicion_y){
			realentizar = _realentizar;
			tiempo = _tiempo;
		}
		
		 // Método de ataque
	    void atacarEnemigos(std::vector<Enemigo>& enemigos){
	    	for (size_t i = 0; i < enemigos.size(); ++i) {
   			float distancia = sqrt(pow(posicion.first - enemigos[i].getPosicion().first, 2) + pow(posicion.second - enemigos[i].getPosicion().second, 2));
    		if (distancia <= alcance) {
        		enemigos[i].set_velocidad(std::max(0.0f, enemigos[i].getVelocidad() - realentizar));
        		std::cout << "Enemigo ralentizado! Velocidad restante: " << enemigos[i].getVelocidad()<< " por " << tiempo << " segundos." << std::endl;
    		}
		}
	}
	
	    // Imprime datos específicos
	    void imprimeDatos() const {
	        cout << "---- Torre congeladora ----" << endl;
			Torre::imprimeDatos();
	        std::cout << "Realentizar: " << realentizar << ", Tiempo: " << tiempo << " segundos" << std::endl;
	    }
	
};

#endif

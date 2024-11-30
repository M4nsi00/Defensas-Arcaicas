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
		
		 // Método de realentizar al enemigo
		 void realentizarEnemigo(Enemigo& enemigo) {
    		enemigo.set_velocidad(max(0.0f, enemigo.get_velocidad() - realentizar));
    		cout << "Enemigo ralentizado! Velocidad restante: " << enemigo.get_velocidad()<< " por " << tiempo << " segundos." << endl;
		}
		
		//Metodo que ataca al enemigo y tambien usa la funcion realentizarEnemigo para aplicar el efecto de la torre 
	    void atacarEnemigos(vector<Enemigo>& enemigos) {
    	for (size_t i = 0; i < enemigos.size(); ++i) {
        float distancia = sqrt(pow(posicion.first - enemigos[i].get_posicion().first, 2) + pow(posicion.second - enemigos[i].get_posicion().second, 2)
        );

        if (distancia <= alcance) {
            // Usa el método `realentizarEnemigo` para aplicar el efecto
            realentizarEnemigo(enemigos[i]);
        }
    }
}
	
	    // Imprime datos de la torre
	    void imprimeDatos() const {
	        cout << "---- Torre congeladora ----" << endl;
			Torre::imprimeDatos();
	        cout << "Realentizar: " << realentizar << ", Tiempo: " << tiempo << " segundos" << endl;
	    }
	
};

#endif

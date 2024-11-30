#ifndef ESPECTRO_H
#define ESPECTRO_H

#include "Enemigo.h"
#include <iostream>

using namespace std;

class Espectro : public Enemigo{
	
	private: 
	int tiempo_invisible; //Variable que determina cuanto tiempo el enemigo dura invicible
	
	public:
		//Constructores
		Espectro(){
			tiempo_invisible = 3;
		}
		
		Espectro(int _tiempo_invisible, float _vida, float _velocidad, float _posicion_x, float _posicion_y) : Enemigo(_vida, _velocidad, _posicion_x, _posicion_y){
			tiempo_invisible = _tiempo_invisible;
		}
		
		//Getters
		int get_tiempo_invisible(){
			return tiempo_invisible;
		}
		
		//Setters
		void set_tiempo_invisible(int _tiempo_invisible){
			tiempo_invisible = _tiempo_invisible;
		}
		
		//Metodos
		void invisible(int tiempo){
			tiempo_invisible = tiempo;
			cout << "Duración de la invisibilidad: " << tiempo_invisible << " segundos" << endl;
		}
		
		void mover() override {  // Sobreescribir el método de movimiento
        if (tiempo_invisible > 0) {
            cout << "Espectro invisible, no se mueve." << endl;
    		tiempo_invisible;
        } else {
            Enemigo::mover();
        }
    }
		
		void imprimeDatos(){
			cout << "---- Enemigo espectro ----" << endl;
			Enemigo::imprimeDatos();
			cout << "Duración de la invisibilidad: " << tiempo_invisible << " segundos" << endl;
		}
		
};

#endif

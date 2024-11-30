#ifndef TANQUE_H
#define TANQUE_H

#include "Enemigo.h"
#include <iostream>

using namespace std;

class Tanque : public Enemigo {
private:
    int escudo;  // Vida del escudo

public:
    // Constructor por defecto
    Tanque() : Enemigo(){
		escudo = 0;
	}

    // Constructor personalizado
    Tanque(int _escudo, float _vida, float _velocidad, float _posicion_x, float _posicion_y) : Enemigo(_vida, _velocidad, _posicion_x, _posicion_y){
		escudo = _escudo;
	}

    // Getter del escudo
    int get_escudo() const {
        return escudo;
    }

    // Setter del escudo
    void set_escudo(int _escudo) {
        escudo = _escudo;
    }

    // Método para perder escudo
    void perderEscudo(int cantidad) {
        escudo -= cantidad;  // Reducir el escudo por la cantidad especificada
        if (escudo <= 0) {
            escudo = 0;  // Asegurarse de que el escudo no sea negativo
            cout << "El escudo del tanque ha sido destruido!" << endl;
        } else {
            cout << "El tanque aún tiene " << escudo << " puntos de escudo." << endl;
        }
    }
    
    void mover() override {  // Sobreescribir el método de movimiento
            Enemigo::mover();
        }
    
    void imprimeDatos(){
			cout << "---- Enemigo Tanque ----" << endl;
			Enemigo::imprimeDatos();
			cout << "Duración del escudo: " << escudo << endl;
		}
    
};

#endif

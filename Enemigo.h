#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>
#include <string>
#include <utility> // Para la posición en dos dimensiones

using namespace std;

class Enemigo {
protected:
    float vida;
    float velocidad;
    pair<float, float> posicion; // Posición en dos dimensiones (eje x, eje y)

public:
    // Constructor por defecto
    Enemigo() {
        vida = 50;
        velocidad = 0.5;
        posicion = {0, 0};
    }

    // Constructor personalizado
    Enemigo(float _vida, float _velocidad, float _posicion_x, float _posicion_y) {
        vida = _vida;
        velocidad = _velocidad;
        posicion = {_posicion_x, _posicion_y};
    }
    
    virtual ~Enemigo(){
    	
	}

    // Getters
    float get_vida() const {
        return vida;
    }

    float get_velocidad() const {
        return velocidad;
    }

    pair<float, float> get_posicion() const {
        return posicion;
    }

    // Setters
    void set_vida(float _vida) {
        vida = _vida;
    }

    void set_velocidad(float _velocidad) {
        velocidad = _velocidad;
    }

    void set_posicion(float _posicion_x, float _posicion_y) {
        posicion = {_posicion_x, _posicion_y};
    }
    
    //Metodos
    virtual void mover(){
    	posicion.first += velocidad;
	}
	
	virtual void imprimeDatos() const{
		cout << "Vida: "<< vida << endl;
		cout << "Velocidad: " << velocidad << endl;
		cout <<"Posicion (" << posicion.first << "," << posicion.second << ")"<< endl;
	}
};
#endif

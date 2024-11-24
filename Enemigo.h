#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>
#include <string>
#include <utility> // Para la posición en dos dimensiones

class Enemigo {
private:
    float vida;
    float velocidad;
    std::pair<float, float> posicion; // Posición en dos dimensiones (eje x, eje y)

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

    // Getters
    float getVida() const {
        return vida;
    }

    float getVelocidad() const {
        return velocidad;
    }

    std::pair<float, float> getPosicion() const {
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
    void mover(){
    	posicion.first += velocidad;
	}
	void imprimeDatos() const{
		std::cout << "Vida: "<< vida << std::endl;
		std::cout << "Velocidad: " << velocidad << std::endl;
		std::cout <<"Posicion (" << posicion.first << "," << posicion.second << ")"<< std::endl;
	}
};
#endif

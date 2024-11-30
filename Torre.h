#ifndef TORRE_H
#define TORRE_H

#include "Enemigo.h"
#include <iostream>
#include <utility> // Para la posición en dos dimensiones
#include <cmath>   // Para la función abs

using namespace std;

class Torre {
protected:
    float dano;
    float alcance;
    int coste;
    pair<float, float> posicion; // Posición de la torre en el mapa (x, y)

public:
    // Constructor por defecto
    Torre(){
    	dano = 10;
    	alcance = 5;
    	coste = 50;
    	posicion = pair<float, float>(0, 0);
	}

    // Constructor personalizado
    Torre(float _dano, float _alcance, int _coste, float _posicion_x, float _posicion_y) {
    dano = _dano;
    alcance = _alcance;
    coste = _coste;
    posicion = pair<float, float>(_posicion_x, _posicion_y); // Inicializar la posición
	}

    
	virtual ~Torre() = default; //Destructor virtual
	
	// Getters
    float get_dano() const {
        return dano;
    }

    float get_alcance() const {
        return alcance;
    }

    int get_coste() const {
        return coste;
    }
    pair<float, float> get_posicion() const {
        return posicion;
    }


    // Setters
    void set_dano(float _dano) {
        dano = _dano;
    }

    void set_alcance(float _alcance) {
        alcance = _alcance;
    }

    void set_coste(int _coste) {
        coste = _coste;
    }
    
    void set_posicion(float _posicion_x, float _posicion_y) {
        posicion = {_posicion_x, _posicion_y};
    }

    // Método para verificar si el enemigo está dentro del alcance de la torre
    virtual bool enRango(pair<float, float> enemigoPos) const {
        float distancia = abs(posicion.first - enemigoPos.first) + abs(posicion.second - enemigoPos.second);
        return distancia <= alcance;
    }

    // Método para atacar al enemigo
    virtual void atacar(Enemigo& enemigo) {
        if (enRango(enemigo.get_posicion())) {
            enemigo.set_vida(enemigo.get_vida() - dano);  // Reducir la vida del enemigo
            cout << "Enemigo atacado! Vida restante: " << enemigo.get_vida() << endl;
        } else {
            cout << "Enemigo fuera de alcance." << endl;
        }
    }
    

    // Método para imprimir los datos de la torre
    virtual void imprimeDatos() const {
        cout << "Dano: " << dano << endl;
        cout << "Alcance: " << alcance << endl;
        cout << "Posicion: (" << posicion.first << ", " << posicion.second << ")" << endl;
    }
};

#endif

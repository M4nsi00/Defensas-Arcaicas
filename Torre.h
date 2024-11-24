#ifndef TORRE_H
#define TORRE_H

#include "Enemigo.h"
#include <iostream>
#include <utility> // Para la posición en dos dimensiones
#include <cmath>   // Para la función abs

class Torre {
private:
    float dano;
    float alcance;
    int coste;
    std::pair<float, float> posicion; // Posición de la torre en el mapa (x, y)

public:
    // Constructor por defecto
    Torre() : dano(10), alcance(5), coste(50), posicion({0, 0}) {}

    // Constructor personalizado
    Torre(float _dano, float _alcance, int _coste, float _posicion_x, float _posicion_y)
        : dano(_dano), alcance(_alcance), coste(_coste), posicion({_posicion_x, _posicion_y}) {}

    // Getters
    float getDano() const {
        return dano;
    }

    float getAlcance() const {
        return alcance;
    }

    int getCoste() const {
        return coste;
    }

    std::pair<float, float> getPosicion() const {
        return posicion;
    }

    // Setters
    void setDano(float _dano) {
        dano = _dano;
    }

    void setAlcance(float _alcance) {
        alcance = _alcance;
    }

    void setCoste(int _coste) {
        coste = _coste;
    }

    // Método para verificar si el enemigo está dentro del alcance de la torre
    bool enRango(std::pair<float, float> enemigoPos) const {
        float distancia = abs(posicion.first - enemigoPos.first) + abs(posicion.second - enemigoPos.second);
        return distancia <= alcance;
    }

    // Método para atacar al enemigo
    void atacar(Enemigo& enemigo) {
        if (enRango(enemigo.getPosicion())) {
            enemigo.set_vida(enemigo.getVida() - dano);  // Reducir la vida del enemigo
            std::cout << "Enemigo atacado! Vida restante: " << enemigo.getVida() << std::endl;
        } else {
            std::cout << "Enemigo fuera de alcance." << std::endl;
        }
    }

    // Método para imprimir los datos de la torre
    void imprimeDatos() const {
        std::cout << "Dano: " << dano << std::endl;
        std::cout << "Alcance: " << alcance << std::endl;
        std::cout << "Posicion: (" << posicion.first << ", " << posicion.second << ")" << std::endl;
    }
};

#endif

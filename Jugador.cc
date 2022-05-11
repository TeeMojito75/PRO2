#include "Jugador.hh"
#include <iostream>
using namespace std;

Jugador::Jugador() {
    nombre = "null";
    torneos_disputados = 0;
    partidos.first = 0;
    partidos.second = 0;
    posicion = 0;
    puntos = 0;
    sets.first = 0;
    sets.second = 0;
    juegos.first = 0;
    juegos.second = 0;
}

Jugador::Jugador(string nombre) {
    this->nombre = nombre;
    torneos_disputados = 0;
    partidos.first = 0;
    partidos.second = 0;
    posicion = 0;
    puntos = 0;
    sets.first = 0;
    sets.second = 0;
    juegos.first = 0;
    juegos.second = 0;
}

void Jugador::actu_stats(pair<int, int>& j, pair<int, int>& s, pair<int, int>& p, int punt) {
    this->juegos.first = j.first;
    this->juegos.second = j.second;
    this->partidos.first = p.first;
    this->partidos.second = p.second;
    this->sets.first = s.first;
    this->sets.second = s.second;
    this->puntos = punt;
    this->torneos_disputados += 1;
}

void Jugador::modificar_posicion(const int pos) {
    posicion = pos;
}

void Jugador::escriure_jug() {
    cout << nombre << ' ' << "Rk:" << posicion << ' ' << "Ps:" << puntos << ' ' << "Ts:" << torneos_disputados << ' ';
    cout << "WM:" << partidos.first << ' ' << "LM:" << partidos.second << ' ';
    cout << "WS:" << sets.first << ' ' << "LS:" << sets.second << ' ';
    cout << "WG:" << juegos.first << ' ' << "LG:" << juegos.second << endl;
}

void Jugador::escriure_rank() {
    cout << posicion << ' ' << nombre << ' ' << puntos << endl;
}

int Jugador::consultar_pos() const{
    return posicion;
}

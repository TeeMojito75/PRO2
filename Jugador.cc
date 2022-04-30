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

void Jugador::modificar_torneosd(int td) {
    this->torneos_disputados = td;
}

void Jugador::modificar_partidos(pair<int, int>& p) {
    this->partidos.first = p.first;
    this->partidos.second = p.second;
}

void Jugador::modificar_sets(pair<int, int>& s) {
    this->sets.first = s.first;
    this->sets.second = s.second;
}

void Jugador::modificar_juegos(pair<int, int>& j) {
    this->juegos.first = j.first;
    this->juegos.second = j.second;
}

void Jugador::modificar_puntuacion(int punt) {
    this->puntos = punt;
}

void Jugador::modificar_posicion(const int pos) {
    this->posicion = pos;
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

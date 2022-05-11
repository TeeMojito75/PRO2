#include "Cjt_jugadores.hh"
#include <algorithm>
using namespace std;

void Cjt_jugadores::lectura_ini_jug() {
    int n;
    string nombre;
    cin >> n;
    pair<map<string, Jugador>::iterator, bool> it;
    for (int i = 1; i <= n; ++i) {
        cin >> nombre;
        Jugador jug = Jugador(nombre);
        jug.modificar_posicion(i);
        it = jugadores.insert(make_pair(nombre, jug));
        ranking.push_back(it.first);
    }
} 

void Cjt_jugadores::nuevo_jugador(string& nombre) {
    Jugador jug = Jugador(nombre); 
    int p = ranking.size() + 1;
    jug.modificar_posicion(p);
    pair<map<string, Jugador>::iterator, bool> it;
    it = jugadores.insert(make_pair(nombre, jug));
    ranking.push_back(it.first);
    cout << jugadores.size() << endl;
}

void Cjt_jugadores::eliminar_jugador(string& nombre) {
    map<string, Jugador>::const_iterator it;
    it = jugadores.find(nombre);
    int pos_v = it->second.consultar_pos();
    int n = ranking.size();
    for (int i = pos_v; i < n; ++i) {
        ranking[i]->second.modificar_posicion(i);
        ranking[i-1] = ranking [i];
    }
    ranking.pop_back();
    jugadores.erase(it);
}

void Cjt_jugadores::listar_jugadores() {
    int n = jugadores.size();
    cout << n << endl;
    for (map<string, Jugador>::iterator it = jugadores.begin(); it != jugadores.end(); ++it) {
        it->second.escriure_jug();
    }
}

void Cjt_jugadores::listar_ranking() {
    int n = ranking.size();
    for (int i = 0; i < n; ++i) ranking[i]->second.escriure_rank();
}

bool Cjt_jugadores::existe_jugador(string& nombre) {
    if (jugadores.find(nombre) != jugadores.end()) return true;
    return false;
}

int Cjt_jugadores::num_jugadores() {
    return jugadores.size();
}

void Cjt_jugadores::consultar_jugador(string& nombre) {
    map<string, Jugador>::iterator it = jugadores.find(nombre);
    it->second.escriure_jug();
}

string Cjt_jugadores::consultar_nombre(int n) {
    return ranking[n-1]->first;
}

map<string, Jugador>::iterator Cjt_jugadores::consultar_conjunto(string s) {
    map<string, Jugador>::iterator it = jugadores.find(s);
    return it;
}

bool cmp(map<string, Jugador>::iterator& it, map<string, Jugador>::iterator& it2 ) {
    if (it->second.consultar_puntos() == it2->second.consultar_puntos()) return it->second.consultar_pos() < it2->second.consultar_pos();
    else return  it->second.consultar_puntos() > it2->second.consultar_puntos();
}

void Cjt_jugadores::actualizar_ranking() {
    sort(ranking.begin(), ranking.end(), cmp);
    for (int i = 0; i < ranking.size(); ++i) {
        ranking[i]->second.modificar_posicion(i+1);
    }
}


#include "Cjt_jugadores.hh"
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

//Actualitzar per eliminar el jugador de tots els torneigs
void Cjt_jugadores::eliminar_jugador(string& nombre) {
    pair<map<string, Jugador>::iterator, bool> it;
    it.first = jugadores.find(nombre);
    int pos_v = it.first->second.consultar_pos();
    int n = ranking.size();
    int aux;
    for (int i = pos_v; i < n; ++i) {
        aux = ranking[i]->second.consultar_pos();
        ranking[i]->second.modificar_posicion(ranking[i-1]->second.consultar_pos());
        ranking[i-1]->second.modificar_posicion(aux);
        swap(ranking[i-1], ranking[i]);
    }
    ranking.pop_back();
    jugadores.erase(nombre);
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

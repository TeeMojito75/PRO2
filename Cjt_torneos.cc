#include "Cjt_torneos.hh"
using namespace std;

void Cjt_torneos::lectura_ini_tor() {
    int n;
    cin >> n;
    int cat; string nombre;
    for (int i = 0; i < n; ++i) {
        cin >> nombre >> cat;
        Torneo torn = Torneo(nombre, cat);
        torneos.insert(make_pair(nombre, torn));
    }
}

void Cjt_torneos::listar_torneos(Cjt_categorias& c) {
    int n = torneos.size();
    cout << n << endl;
    for (map<string, Torneo>::iterator it = torneos.begin(); it != torneos.end(); ++it){
        cout << it->first << ' '; 
        it->second.escribir_categoria(c);
    }
}

bool Cjt_torneos::existe_torneo(string nombre) const {
    if (torneos.find(nombre) != torneos.end()) return true;
    return false;
}

int Cjt_torneos::num_torneos() const {
    return torneos.size();
}

void Cjt_torneos::nuevo_torneo(string nombre, int c) { 
    Torneo t = Torneo(nombre, c);
    torneos.insert(make_pair(nombre, t));
}

void Cjt_torneos::baja_torneo(string nombre, Cjt_jugadores& j) {
    map<string, Torneo>::iterator it = torneos.find(nombre);
    it->second.quitar_puntos(j);
    j.actualizar_ranking();
    torneos.erase(nombre); 
}

void Cjt_torneos::iniciar_torneo(string nom, Cjt_jugadores& j) {
    int n, p;
    cin >> n;
    Participantes part;
    map<string, Torneo>::iterator it = torneos.find(nom);
    for (int i = 0; i < n; ++i) {
        cin >> p;
        part.nombre = j.consultar_nombre(p);
        it->second.ampliar_participantes(part);
    } 
    it->second.inscripciones(n);
}

void Cjt_torneos::finalizar_torneo(string nom, const Cjt_categorias& c, Cjt_jugadores& j) {
    map<string, Torneo>::iterator it = torneos.find(nom);
    it->second.results(c, j);
    j.actualizar_ranking();
}



     
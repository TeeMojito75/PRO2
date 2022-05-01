#include "Torneo.hh"
#include "Cjt_categorias.hh"
using namespace std;

Torneo::Torneo(string nom, int c) {
    nombre = nom;
    cat = c;
    jug = vector<Participantes> (0);
    n_participantes = 0;
}

int Torneo::num_jugadores() {
    return n_participantes;
}

void Torneo::modificar_npart(int n) {
    n_participantes = n;
}

void Torneo::modificar_match(int pos, int win, int lose) {
    jug[pos].match.first = win;
    jug[pos].match.second = lose;
}

void Torneo::modificar_set(int pos, int win, int lose) {
    jug[pos].set.first = win;
    jug[pos].set.second = lose;
}

void Torneo::modificar_game(int pos, int win, int lose) {
    jug[pos].game.first = win;
    jug[pos].game.second = lose;
}

void Torneo::modificar_pts(int pos, int pts) {
    jug[pos].puntos = pts;
}

void Torneo::escribir_categoria(Cjt_categorias& c) {
    c.consultar_categoria(cat);
}

void Torneo::ampliar_participantes(Participantes part) {
    jug.push_back(part);
}

BinTree<int> Torneo::inscripciones_t(int nodos, int n, int pos) {
    if (n <= nodos) {
        cout << pos << '.' << jug[pos - 1].nombre;
        return BinTree<int>(pos);
        
    }
    nodos *= 2;
    if ((nodos > n) and (nodos - n >= pos)) {
        cout << pos << '.' << jug[pos - 1].nombre;
        return BinTree<int>(pos);
    }
    BinTree<int> iz, der;
    cout << "(";
    iz = inscripciones_t(nodos, n, pos);
    cout << ' ';
    der = inscripciones_t(nodos, n, nodos + 1 - pos);
    cout << ')';
    return BinTree<int>(pos, iz, der);
}

void Torneo::inscripciones(int n) {
    enfrentamientos = inscripciones_t(1, n, 1);
    cout << endl;
}

#include "Torneo.hh"
#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"
using namespace std;

Torneo::Torneo(string nom, int c) {
    nombre = nom;
    cat = c;  
    n_participantes = 0;
}

int Torneo::num_jugadores() {
    return n_participantes;
}

void Torneo::modificar_npart(int n) {
    n_participantes = n;
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

void Torneo::results(const Cjt_categorias& c, Cjt_jugadores& j) {
    resultados = i_results();
    actualizar_enfrentamientos(resultados, enfrentamientos, 1, c);
    escribir_resultados(resultados, enfrentamientos);
    cout << endl;
    escribir_puntos();
    actualizar_jugadores(jug, j);
}

BinTree<string> Torneo::i_results() {
    string partido;
    cin >> partido;

    if (partido != "0") {
        BinTree<string> e, d;
        e = i_results();
        d = i_results();
        return BinTree<string>(partido, e, d);
    }
       return BinTree<string> ();
}


void Torneo::escribir_resultados(const BinTree<string>& R, const BinTree<int>& T) {
    if (not R.empty()) {
        cout << '(';
        cout << T.left().value() << '.' << jug[T.left().value()-1].nombre;
        cout << " vs ";
        cout << T.right().value() << '.' << jug[T.right().value()-1].nombre;
        cout << ' ' << R.value();
        escribir_resultados(R.left(), T.left());
        escribir_resultados(R.right(), T.right());
        cout << ')';
    }
}

void Torneo::escribir_puntos() {
    for (int i = 0; i < jug.size(); ++i) {
        if (jug[i].puntos != 0) cout << i+1 << '.' << jug[i].nombre << ' ' << jug[i].puntos << endl;
        ultima_ed.insert(make_pair(jug[i].nombre, jug[i].puntos));
    }
}

void Torneo::actualizar_enfrentamientos(const BinTree<string>& R, BinTree<int>& T, int nivel, const Cjt_categorias& c) {
    if (T.empty()) return;
    BinTree<int> e, d;
    e = T.left();
    d = T.right();
    
    if (not R.left().empty()) actualizar_enfrentamientos(R.left(), e, nivel+1, c);
    if (not R.right().empty()) actualizar_enfrentamientos(R.right(), d, nivel+1, c);

    int win;
    int jleft = 0; int jright = 0;
    int sleft = 0; int sright = 0;
    int mleft = 0; int mright = 0;

    if (R.value().size() == 3) {
        if (R.value()[0] == '1') {
            win = e.value();
            mleft += 1;
        }
        else {
            win = d.value();
            mright += 1;
        } 
    }
    else if (R.value().size() == 7) {
        if (R.value()[4] > R.value()[6]) {
            win = e.value();
            jleft = (R.value()[0]-'0') + (R.value()[4]-'0');
            jright = (R.value()[2]-'0') + (R.value()[6]-'0');
            sleft += 2;
            mleft += 1;
        }
        else {
            win = d.value();
            jleft = (R.value()[0]-'0') + (R.value()[4]-'0');
            jright = (R.value()[2]-'0') + (R.value()[6]-'0');
            sright += 2; 
            mright += 1;
        }
    }
    else {
        if (R.value()[8] > R.value()[10]) {
            win = e.value();
            jleft = (R.value()[0]-'0') + (R.value()[4]-'0') + (R.value()[8]-'0');
            jright = (R.value()[2]-'0') + (R.value()[6]-'0') + (R.value()[10]-'0');
            sright += 1;
            sleft += 2;
            mleft += 1;
        }
        else {
            win = d.value();
            jleft = (R.value()[0]-'0') + (R.value()[4]-'0') + (R.value()[8]-'0');
            jright = (R.value()[2]-'0') + (R.value()[6]-'0') + (R.value()[10]-'0');
            sright += 2;
            sleft  += 1;
            mright += 1;
        }
    }
    
    T = BinTree<int>(win, e, d);

    //Actualización de las estadísticas de participantes
    jug[e.value()-1].game.first += jleft;
    jug[e.value()-1].game.second += jright; 
    jug[d.value()-1].game.first += jright;
    jug[d.value()-1].game.second += jleft; 
   
    jug[e.value()-1].set.first += sleft;
    jug[e.value()-1].set.second += sright;
    jug[d.value()-1].set.first += sright;
    jug[d.value()-1].set.second += sleft;
    
    jug[e.value()-1].match.first += mleft;
    jug[e.value()-1].match.second += mright;
    jug[d.value()-1].match.first += mright;
    jug[d.value()-1].match.second += mleft;

    if (e.value() != win) jug[e.value()-1].puntos =  c.puntos(cat, nivel);
    else if (d.value() != win) jug[d.value()-1].puntos = c.puntos(cat, nivel);
    jug[T.value()-1].puntos = c.puntos(cat, 0);
}

void Torneo::actualizar_jugadores(const vector<Participantes>& v, Cjt_jugadores& j) {
    map<string, Jugador>::iterator it;
    for (int i = 0; i < v.size(); ++i) {
        it = j.consultar_conjunto(jug[i].nombre);
        it->second.actu_stats(jug[i].game, jug[i].set, jug[i].match, jug[i].puntos);
    }
}



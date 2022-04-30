#include "Cjt_categorias.hh"
using namespace std;

Cjt_categorias::Cjt_categorias() {
    vector<categoria> categorias(0);

}

void Cjt_categorias::lectura_ini_cat() {
    int cats, puntos;
    cin >> cats >> puntos;
    categorias = vector<categoria> (cats);
    
    
    for (int i = 0; i < cats; ++i) {
        categorias[i].puntuaciones = vector<int> (puntos);
        cin >> categorias[i].nombre;
    }
    for (int j = 0; j < cats; ++j) {
        for (int k = 0; k < puntos; ++k) cin >> categorias[j].puntuaciones[k];
    }
}

bool Cjt_categorias::existe_categoria(int cat) {
    if (cat > categorias.size()) return false;
    else return true;
}

void Cjt_categorias::listar_categorias() {
    int n = categorias.size();
    int p = categorias[0].puntuaciones.size();
    cout << n << ' ' << p << endl;
    for (int i = 0; i < n; ++i) {
        cout << categorias[i].nombre;
        for (int j = 0; j < p; ++j) cout << ' ' <<  categorias[i].puntuaciones[j];
        cout << endl;
    }
}

void Cjt_categorias::consultar_categoria(int cat) {
    cout << categorias[cat-1].nombre << endl;
}
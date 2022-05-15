#include "Cjt_categorias.hh"
using namespace std;

Cjt_categorias::Cjt_categorias() 
{
    vector<categoria> categorias(0);
}

void Cjt_categorias::lectura_ini_cat() 
{
    int cats, puntos;
    cin >> cats >> puntos;
    k = puntos;
    categorias = vector<categoria> (cats);
    
    for (int i = 0; i < cats; ++i) {
        categorias[i].puntuaciones = vector<int> (puntos);
        cin >> categorias[i].nombre;
    }
    for (int j = 0; j < cats; ++j) {
        for (int k = 0; k < puntos; ++k) cin >> categorias[j].puntuaciones[k];
    }
}

bool Cjt_categorias::existe_categoria(int cat) const
{
    if (cat > categorias.size() or cat <= 0) return false;
    else return true;
}

void Cjt_categorias::consultar_categoria(int cat) const
{
    cout << categorias[cat-1].nombre << endl;
}

int Cjt_categorias::puntos(int cat, int nivel) const 
{
    return categorias[cat-1].puntuaciones[nivel];
}

void Cjt_categorias::listar_categorias() 
{
    int n = categorias.size();
    cout << n << ' ' << k << endl;
    for (int i = 0; i < n; ++i) {
        cout << categorias[i].nombre;
        for (int j = 0; j < k; ++j) cout << ' ' <<  categorias[i].puntuaciones[j];
        cout << endl;
    }
}
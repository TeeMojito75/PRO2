/**  @mainpage Circuito de Torneos de Tenis con Ranking.

El programa principal se encuentra en el modulo <em>main.cc</em>
Las clases diseñadas para realizar la práctica a partir de la especificación son las siguientes:
<ul>
   <li>Torneo</li>
   <li>Cjt_torneos</li>
   <li>Cjt_categorias</li>
   <li>Cjt_jugadores</li>
   <li>Jugador</li>
</ul>
*/

#include "Cjt_jugadores.hh"
#include "Cjt_torneos.hh"
#include "Cjt_categorias.hh"

/** @file program.cc
    @brief programa principal para la práctica <em>Gestión de torneos de tenis</em>
 */ 

// inclusion de clases (redundantes, únicamente para la mejor visualización del diagrama modular)
#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @brief programa principal para la practica <em>Circuito de torneos de tenis</em>
 */

int main() {	
	Cjt_categorias c;
    Cjt_torneos t;
    Cjt_jugadores j;
    
    c.lectura_ini_cat();
    t.lectura_ini_tor();
    j.lectura_ini_jug();

    string cm;
    cin >> cm;
    while (cm != "fin") {
	
	    if (cm == "nuevo_jugador" or cm == "nj") {
			cout << '#' << cm;
			string nombre;
			cin >> nombre;
			cout << ' ' << nombre << endl;
	    	if (j.existe_jugador(nombre)) cout << "error: ya existe un jugador con ese nombre" << endl;
	    	else {
				j.nuevo_jugador(nombre);
			}
		} 

		else if (cm == "nuevo_torneo" or cm == "nt") {
			string nombre;
			int cat;
			cin >> nombre >> cat;
			cout << '#' << cm << ' ' << nombre << ' ' << cat << endl;
			if (not c.existe_categoria(cat)) cout << "error: la categoria no existe" << endl;
			else if (c.existe_categoria(cat) and t.existe_torneo(nombre)) cout << "error: ya existe un torneo con ese nombre" << endl;
			else {
				t.nuevo_torneo(nombre, cat);
				cout << t.num_torneos() << endl;
			}
		
		}
          
		else if (cm == "baja_jugador" or cm == "bj") {
			string nombre;
			cin >> nombre;
			cout << '#' << cm << ' ' << nombre << endl;
	 		if (not j.existe_jugador(nombre)) cout << "error: el jugador no existe" << endl;
	 		else {
				t.eliminar_ediciones(nombre);
				j.eliminar_jugador(nombre);
				cout << j.num_jugadores() << endl;
	 	   }
		}

		else if (cm == "baja_torneo" or cm == "bt") {
			string nombre;
			cin >> nombre;
			cout << '#' << cm << ' ' << nombre << endl;
		    if (not t.existe_torneo(nombre)) cout << "error: el torneo no existe" << endl;
	   	 	else {
			t.baja_torneo(nombre, j);
			cout << t.num_torneos() << endl;
	    	}
		}
	
		else if (cm == "iniciar_torneo" or cm == "it") { 
			string nombre;
			cin >> nombre;
		 	cout << '#' << cm << ' ' << nombre << endl; 
			t.iniciar_torneo(nombre, j);
		}
		else if (cm == "finalizar_torneo" or cm == "ft") {
			string nombre;
			cin >> nombre;
			cout << '#' << cm << ' ' << nombre << endl;
			t.finalizar_torneo(nombre, c, j); 
		}
	
		else if (cm == "listar_ranking" or cm == "lr") {
			cout << '#' << cm << endl;
		    j.listar_ranking();
		}
		
		else if (cm == "listar_jugadores" or cm == "lj") {
			cout << '#' << cm << endl;
		    j.listar_jugadores();
		}
		
		else if (cm == "consultar_jugador" or cm == "cj") {
			string nombre;
			cin >> nombre;
			cout << '#' << cm << ' ' << nombre << endl;
	 		if (not j.existe_jugador(nombre)) cout << "error: el jugador no existe" << endl;
	 		else j.consultar_jugador(nombre);
		}
		
		else if (cm == "listar_torneos" or cm == "lt") {
			cout << '#' << cm << endl;
		    t.listar_torneos(c);
		}
		
		else if (cm == "listar_categorias" or cm == "lc") {
			cout << '#' << cm << endl;
		    c.listar_categorias();
		}
		cin >> cm;
    }

	
}

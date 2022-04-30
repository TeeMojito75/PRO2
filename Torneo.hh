/** @file Torneo.hh
    @brief Especificación de la clase Torneo
  */

#ifndef TORNEO_HH
#define TORNEO_HH

#include "Jugador.hh"
#include "Cjt_categorias.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include "BinTree.hh"
#endif


struct Participantes {
	string nombre;
	int puntos;
	pair<int, int> match;
	pair<int, int> set;
	pair<int, int> game;
};


/** @class Torneo
    @brief Representa un torneo del circuito
*/ 

class Torneo {

    private:
	string nombre;
	int cat;
	int n_participantes;
	vector<Participantes> jug;
	BinTree<int> enfrentamientos;

    public:

	//constructor 
	/** @brief Creadora por defecto
	    \pre <em>cierto</em>
	    \post Torneo creado con nombre y categoría
	 */ 
	Torneo(string nombre, int cat);

	//consultoras
	/** @brief Da el numero de jugadores en un torneo
	    \pre <em>nombre</em> es el nombre de un torneo existente
	    \post Se imprime el valor de jugadores totales de un torneo
	 */ 
	int num_jugadores();

	//Modificadoras
	/** @brief Modifica el valor del número de participantes
	 *  \pre <em>nombre</em> es el nombre de un torneo, n_participantes >= 0
	 * 	\post Se ha modificado el parámetro implícito
	 */
	void modificar_npart(int n);

	/** @brief Modifica los partidos del participante
	 *	\pre pair.first >= 0, pair.second >= 0
	 	\post Los valores del parámetro implícito han sido modificados
	*/
	void modificar_match(int pos, int win, int lose);

	/** @brief Modifica los partidos del participante
	 *	\pre pair.first >= 0, pair.second >= 0
	 	\post Los valores del parámetro implícito han sido modificados
	*/
	void modificar_set(int pos, int win, int lose);

	/** @brief Modifica los partidos del participante
	 *	\pre pair.first >= 0, pair.second >= 0
	 	\post Los valores del parámetro implícito han sido modificados
	*/
	void modificar_game(int pos, int win, int lose);

	/** @brief Modifica los partidos del participante
	 *	\pre pair.first >= 0, pair.second >= 0
	 	\post Los valores del parámetro implícito han sido modificados
	*/
	void modificar_pts(int pos, int puntos);

	/** @brief Escribe el nombre de la categoría
	 *	\pre Cjt_categorias es un conjunto no vacío
	 	\post Se ha escrito el nombre de la categoría
	*/
	void escribir_categoria(Cjt_categorias& c);

	/** Función usada para añadir los participantes al vector jug desde el conjunto
	 * 	\pre <em>part</em> es uno de los participantes del torneo
	 * 	\post Se ha añadido al participante en el vector
	*/
	void ampliar_participantes(Participantes part);
	
	/** @brief Crea el arbol de inscripciones
	 * 	\pre <em>cierto</em>
	 * 	\post Se ha creado el árbol con los valores de los jugadores inscritos
	*/
	BinTree<int> inscripciones_t(int nodos, int n, int pos); 

	/** @brief Carga los enfrentamientos al árbol implícito del torneo
	 * 	\pre Existe un torneo con un conjunto de participantes
	 * 	\post Se ha creado el árbol con el orden de esos enfrentamientos y se ha impreso el mismo
	*/
	void inscripciones(int n);
};		
#endif

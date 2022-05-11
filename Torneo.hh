/** @file Torneo.hh
    @brief Especificación de la clase Torneo
  */



#ifndef TORNEO_HH
#define TORNEO_HH

#include "Jugador.hh"
#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#include "BinTree.hh"
#endif


/** @class Torneo
    @brief Representa un torneo del circuito
*/ 

struct Participantes {
	string nombre;
	int puntos;
	pair<int, int> match;
	pair<int, int> set;
	pair<int, int> game;
};

class Torneo {

    private:
	string nombre;
	int cat;
	int n_participantes;
	vector<Participantes> jug;
	BinTree<int> enfrentamientos;
	BinTree<string> resultados;

    public:
	//Map que guarda el nombre y los puntos de la última edición del torneo
	map<string, int> ultima_ed;
	
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

	/** @brief Carga los resultados de los partidos del torneo
	 * 	\pre Existe un torneo ya iniciado
	 * 	\post Se han modificado los arboles y printeado los resultados
	*/
	void results(const Cjt_categorias& c, Cjt_jugadores& j);

	/** @brief Crea el arbol de resultados
	 * 	\pre <em>Cierto</em>
	 * 	\post Se ha creado el arbol con los sets de los partidos
	*/
	BinTree<string> i_results();

	/** @brief Imprime los resultados del torneo
     *  \pre Existe el susodicho torneo, con su arbol de emparejamientos y resultados
     *  \post Se han impreso tanto los enfrentamientos como los ganadores de puntos
    */
    void escribir_resultados(const BinTree<string>& R, const BinTree<int>& T);  
	
	/** @brief Se imprimen los jugadores con los puntos ganados y se añaden al map de última edición
	 * 	\pre Se ha finalizado un torneo
	 * 	\post Se han impreso los jugadores con sus puntuajes y se han añadido a la última edición
	*/
	void escribir_puntos();

	/**
	@brief Actualiza el BinTree de enfrnetamientos
	\pre Existe un torneo iniciado con un arbol de enfrentamientos
	\post Se han actualizado los nodos del arbol de la forma solicitada
    */
    void actualizar_enfrentamientos(const BinTree<string>& R, BinTree<int>& T, int nivel, const Cjt_categorias& c);
   
   /** @brief Actualiza los jugadores con los puntos ganados
	* 	\pre <em>j</em> es un conjunto no vacio de jugadores y <em>jug</em> es el vector de participantes del torneo
		\post Se han actualizado los parámetros del conjunto de jugadores
	*/
	void actualizar_jugadores(const vector<Participantes>& v, Cjt_jugadores& j);
	

};		
#endif

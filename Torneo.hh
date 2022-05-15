/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef TORNEO_HH
#define TORNEO_HH

#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#include "BinTree.hh"
#endif

/** @brief Estructura que representa los participantes de un torneo
    Cada participante presenta los mismos parámetros que un jugador del conjunto  
*/
struct Participantes 
{
	// Struct usada para separar el conjunto de jugadores con los jugadores de cada torneo.
	// Se usan funciones para pasar los puntos al conjunto

	string nombre; //!< Identificador de cada participante
	int puntos; //!< Puntos que ha ganado el participante en el torneo
	pair<int, int> match; //!< Par de partidos ganados/perdidos
	pair<int, int> set; //!< Par de sets ganados/perdidos
	pair<int, int> game; //!< Par de juegos ganados/perdidos
};

/** @class Torneo
    @brief Representa un torneo del circuito
*/ 

class Torneo 
{
    private:
	string nombre; //!< Identificador de cada torneo
	int cat; //!< Entero que representa la categoría del torneo
	int n_participantes; //!< Número de participantes del torneo
	vector<Participantes> jug; //!< Vector con el conjuntode participantes del torneo
	map<string, int> ultima_ed; //!< Diccionario que almacena los jugadores y los puntos del último torneo disputado
	BinTree<int> enfrentamientos; //!< Árbol con los enfrentamientos al iniciar torneo
	BinTree<string> resultados; //!< Árbol con los resultados de los partidos de los torneos

    public:
	//constructor 
	/** @brief Creadora por defecto
	    \pre <em>cierto</em>
	    \post Torneo creado con nombre y categoría
	*/ 
	Torneo(string nombre, int cat);

	//consultoras
	/** @brief Da el numero de jugadores en un torneo
	    \pre <em>Cierto</em>
	    \post Se imprime el valor de jugadores totales de un torneo
	*/ 
	int num_jugadores();

	//Modificadoras
	/** @brief Modifica el valor del número de participantes
	    \pre <em>n</em> es el entero n que representa el número de participantes 
	   	\post Se ha modificado el parámetro implícito
	*/
	void modificar_npart(int n);

	/** @brief Actualiza el BinTree de enfrnetamientos
		\pre Existe un torneo iniciado con un arbol de enfrentamientos
		\post Se han actualizado los nodos del arbol de la forma solicitada
    */
    void actualizar_enfrentamientos(const BinTree<string>& R, BinTree<int>& T, int nivel, const Cjt_categorias& c);
   
    /** @brief Actualiza los jugadores con los puntos ganados
		\pre <em>j</em> es un conjunto no vacio de jugadores y <em>jug</em> es el vector de participantes del torneo
		\post Se han actualizado los parámetros del conjunto de jugadores
	*/
	void actualizar_jugadores(const vector<Participantes>& v, Cjt_jugadores& j);

	/** @brief Función usada para añadir los participantes al vector jug desde el conjunto
	   	\pre <em>part</em> es uno de los participantes del torneo
	   	\post Se ha añadido al participante en el vector
	*/
	void ampliar_participantes(Participantes part);

	/** @brief Elimina los puntos de la edición anterior
	  	\pre <em>Cjt_jugadores</em> es el conjunto no vacío de jugadores
	   	\post Se han eliminado los puntos de la edición de la edición anterior
	*/
	void quitar_puntos(Cjt_jugadores& j);

	/** @brief Pone los puntos a 0 en caso de eliminar jugadores
	   	\pre <em>nombre</em> es el nombre de un presunto jugador
	   	\post Se han puesto los puntos a cero del jugador (en caso de que existe)
	*/
	void puntos_0(const string& nombre);
	
	//Creación de los árboles
	/** @brief Crea el arbol de inscripciones
	   	\pre <em>cierto</em>
	   	\post Se ha creado el árbol con los valores de los jugadores inscritos
	*/
	BinTree<int> inscripciones_t(int nodos, int n, int pos); 

	/** @brief Carga los enfrentamientos al árbol implícito del torneo
	  	\pre Existe un torneo con un conjunto de participantes
	  	\post Se ha creado el árbol con el orden de esos enfrentamientos y se ha impreso el mismo
	*/
	void inscripciones(int n);

	/** @brief Carga los resultados de los partidos del torneo
	   	\pre Existe un torneo ya iniciado
	  	\post Se han modificado los arboles y printeado los resultados
	*/
	void results(const Cjt_categorias& c, Cjt_jugadores& j);

	/** @brief Crea el arbol de resultados
	   	\pre <em>Cierto</em>
	  	\post Se ha creado el arbol con los sets de los partidos
	*/
	BinTree<string> i_results();

	//Funciones de escritura
	/** @brief Imprime los resultados del torneo
        \pre Existe el susodicho torneo, con su arbol de emparejamientos y resultados
        \post Se han impreso tanto los enfrentamientos como los ganadores de puntos
    */
    void escribir_resultados(const BinTree<string>& R, const BinTree<int>& T);  
	
	/** @brief Se imprimen los jugadores con los puntos ganados y se añaden al map de última edición
	   	\pre Se ha finalizado un torneo
	  	\post Se han impreso los jugadores con sus puntuajes y se han añadido a la última edición
	*/
	void escribir_puntos();

	/** @brief Escribe el nombre de la categoría
	 	\pre Cjt_categorias es un conjunto no vacío
	 	\post Se ha escrito el nombre de la categoría
	*/
	void escribir_categoria(Cjt_categorias& c);
	
};		
#endif

/** @file Jugador.hh
    @brief Especificación de la clase Jugador
    */


#ifndef JUGADOR_HH
#define JUGADOR_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @class Jugador
    @brief Representa un jugador del Ranking
    
    Cada jugador presenta los siguientes parámetros:
    - Un string como identificador
    - Un entero representando los torneos disputados
    - Una pareja de enteros para los partidos, sets y juegos ganados y perdidos
    - Un entero para la posición y puntos, respectivamente    
*/

class Jugador {
    
    private:
	string nombre;
	int torneos_disputados;
	pair<int, int> partidos;
	pair<int, int> sets;
	pair<int, int> juegos;
	int posicion;
	int puntos;
		    
    public:

    //constructora
    /** @brief Creadora por defecto
    	\pre <em>Cierto</em>
	    \post Un jugador es creado sin nombre y todos los atributos en 0
	*/
    Jugador();

    /** @brief Creadora con valores
	    \pre <em>nombre</em> es un nombre de jugador
	    \post El resultado es un jugador con nombre <em>nombre</em> y los atributos a 0
    */
    Jugador(string nombre);
    
    //modificadoras
	/** @brief Modificadora de los atributos ganados en un torneo
	    \pre pair juegos >= 0, pair sets >= 0, pair partidos >= 0, puntos >= 0
	    \post El parámetro implícito pasa a tener esas estadísticas modificadas
    */
    void actu_stats(pair<int, int>& j, pair<int, int>& s, pair<int, int>& p, int punt);

    /** @brief Modificadora de la posición
	    \pre <em>pos</em> es la posición de un jugador
	    \post El parámetro implícito pasa a tener <em>pos</em> posición
     */ 
    void modificar_posicion(const int pos);

    /** @brief Actualiza los puntos del jugador
        \pre <em>punto</em> son los puntos del jugador
        \post Se han actualizado los puntos del jugador
    */
    void modificar_puntos(const int punt);

    //escritura
    /** @brief Función de escritura de parámetros
        \pre Todos los parámetros del jugador >= 0
        \post Se han impreso todos los parámetros en orden
    */
    void escriure_jug();

    /** @brief Función de escritura para ranking
        \pre Todos los parámetros del jugador >= 0
        \post Se han impreso los parámetros deseados del jugador
    */
    void escriure_rank();

    //Consultora
    /** @brief Devuelve el valor de la posición en ranking
        \pre posicion >= 0;
        \post Se ha devuelto el valor posición del jugador
    */
    int consultar_pos() const;

    /** @brief Devuelve el valor de puntos del Jugador
        \pre <em>puntos</em> son los puntos del jugador
        \post Se ha devuelto el valor de la puntuación
    */
    int consultar_puntos() const;

};

#endif

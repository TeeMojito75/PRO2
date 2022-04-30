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
    
    Dispone de atributos que definen cada jugador como su puntiación o ranking
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

	Se ejecuta al declarar un jugador
	\pre <em>cierto</em>
	\post Jugador creado es sin nombre y todos los atributos en 0
	*/
    Jugador();

    /** @brief Creadora con valores
	\pre <em>nombre</em> es un nombre de jugador
	\post El resultado es un jugador con nombre <em>nombre</em> y los atributos a 0
    */
    Jugador(string nombre);
    
    //modificadoras
    /** @brief Modificadora atributo torneos disputados
	\pre td >= 0
	\post El parámetro implícito pasa a tener <em>td</em> modificado
    */
    void modificar_torneosd(int td);

    /** @brief Modificadora atributo partidos G y P
	\pre partidos.first >= 0, partidos.second >= 0
	\post El parámetro implícito pasa a tener <em>partidos</em> modificado
    */
    void modificar_partidos(pair<int, int>& p);

    /** @brief Modificadora atributo sets G y P
	\pre sets.first >= 0, sets.second >= 0
	\post El parámetro implícito pasa a tener <em>s</em> sets
    */
    void modificar_sets(pair<int, int>& s);

    /** @brief Modificadora atributo juegos G y P
	\pre juegos.first >= 0, juegos.second >= 0
	\post El parámetro implícito pasa a tener <em>j</em> juegos
    */
    void modificar_juegos(pair<int, int>& j);

    /** @brief Modificadora de los puntos
	\pre punt >= 0
	\post El parámetro implícito pasa a tener <em>punt</em> puntos
     */ 
    void modificar_puntuacion(int punt);

    /** @brief Modificadora de la posición
	\pre pos >= 0;
	\post El parámetro implícito pasa a tener <em>pos</em> posición
     */ 
    void modificar_posicion(const int pos);

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

    /** @brief Devuelve el valor de la posición en ranking
     *  \pre posicion >= 0;
     *  \post Se ha devuelto el valor posición del jugador
    */
    int consultar_pos() const;

};

#endif

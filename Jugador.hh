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
    /** @brief Modificadora de los atributos ganados en un torneo
	\pre partidos.first >= 0, partidos.second >= 0
	\post El parámetro implícito pasa a tener <em>partidos</em> modificado
    */
    void actu_stats(pair<int, int>& j, pair<int, int>& s, pair<int, int>& p, int punt);

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

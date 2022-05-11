/** @file Cjt_jugadores.hh
    @brief Especificación de la clase Cjt_jugadores
 */ 

#ifndef CJT_JUG_HH
#define CJT_JUG_HH

#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#endif

/** @class Cjt_jugadores
    @brief Representa el conjunto de jugadores del circuito
    
    Dispone de ciertas operaciones que afectan al conjunto de jugadores del circuito
*/ 

class Cjt_jugadores {

    private:
    map<string, Jugador> jugadores;
    vector<map<string, Jugador>::iterator> ranking;

    public:
    /** @brief Añade un nuevo jugador al conjunto
	\pre <em>nombre</em> es un nombre de jugador, se inicializan sus estadísticas a 0
	\post el conjunto tiene n+1 jugadores, se ha actualizado el orden de la struct
     */ 
    void nuevo_jugador(string& nombre);

    /** @brief Elimina un jugador del conjunto
	\pre <em>nombre</em> es un nombre de jugador
	\post El conjunto tiene n-1 jugadores, se ha actualizado el orden de la struct
     */ 
    void eliminar_jugador(string& nombre);

    /** @brief Función para acceder al map de Jugadores
     * \pre El conjunto de jugadores no está vacio
     * \post Se da
    */
    map<string, Jugador>::iterator consultar_conjunto(string s);

    /** @brief Actualiza las posiciones del ranking de jugadores
     *  \pre Existe un vector de iteradores no vacios
     *  \post Se han actualizado las posiciones del ranking de acuerdo a la puntuación de los jugadores
    */
    void actualizar_ranking();

    /** @brief Lista por orden lexicográfico a los jugadores con sus estadísticas
	\pre Existe un conjunto no vacío de jugadores con sus atributos
	\post Se ha escrito por el canal de salida el listado de jugadores
     */ 
    void listar_jugadores();

    /** @brief Lista por orden de ranking a los jugadores con sus estadísticas
	\pre Existe un conjunto no vacío de jugadores con sus atributos
	\post Se ha escrito por el canal de salida el listado de jugadores
     */ 
    void listar_ranking();

    /** @brief Devuelve la suma de jugadores del circuito
	\pre Existe un conjunto no vacío de jugadores
	\post <em>num</em> es el nombre total de jugadores
     */ 
    int num_jugadores();

    /** @brief Comprueba si el jugador existe en el conjunto
	\pre <em>nombre</em> es el nombre de un jugador
	\post Devuelve 1 si el jugador ya existía en el conjunto, 0 en otro 	    caso
    */
    bool existe_jugador(const string& nombre); 

    /** @brief Hace la lectura inicial del conjunto desde la consola
        \pre <em>cierto</em>
        \post Se han leido los jugadores del conjunto
    */
    void lectura_ini_jug();

    //consultores
    /** @brief Escribe la información del jugador con el string nombre <em>nombre</em>
	\pre <em>nombre</em> es un nombre de jugador
	\post Se ha escrito el <em>nombre</em> nombre, la <em>pos</em> posición y el resto de 
	estadísticas de un jugador
    */ 
    void consultar_jugador(string& nombre);

    /** @brief Devuelve el nombre del jugador en base a su posición
     *  \pre n es un entero n >= 1 que simboliza la posición en ranking
     *  \post Se ha devuelto el nombre del jugador deseado
    */
    string consultar_nombre(int n);
};

#endif

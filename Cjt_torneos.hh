/** @file Cjt_torneos.hh
    @brief Especificación de la clase Cjt_torneos
 */

#ifndef CJT_TORNEOS_HH
#define CJT_TORNEOS_HH

#include "Cjt_jugadores.hh"
#include "Torneo.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#endif

using namespace std;

/** @class Cjt_torneos
    @brief Representa el conjunto de torneos del ciruito
*/

class Cjt_torneos{

    private:
    map<string, Torneo> torneos;

    public:
    //Modificadoras
	/** @brief empieza un torneo
	    \pre <em>nombre</em> es el nombre de un torneo existente y <em>Cjt_jugadores</em> es un conjunto no vacío
	    \post Se imprime el cuadro de emparejamientos del torneo con nombre <em>nombre</em>
    */
	void iniciar_torneo(string nombre, Cjt_jugadores& j);
	

	/** @brief finaliza un torneo
	    \pre <em>nombre</em> es el nombre de un torneo existente
	    \post Se imprime el cuadro de resultados del torneo con las puntuaciones
    */
    void finalizar_torneo(string nombre, const Cjt_categorias& c, Cjt_jugadores& j);
    

    /** @brief Añade un nuevo torneo en el conjunto
	    \pre c >= 1, <em>nombre</em> es el nombre de un torneo
	    \post Se ha añadido un torneo al conjunto
    */
    void nuevo_torneo(string nombre, int c);
    
    /** @brief Elimina un torneo del conjunto
	    \pre <em>nombre</em> es el nombre de un torneo
	    \post se ha eliminado un torneo del conjunto
    */ 
    void baja_torneo(string nombre, Cjt_jugadores& j);

    /** @brief Elimina al jugador de todas las últimas ediciones
        \pre <em>cierto</em>
        \post Se ha eliminado al jugador de todas las últimas ediciones de los torneos
    */
    void eliminar_ediciones(string nombre);

    //Consultoras
    /** @brief Comprueba el nombre de torneos del conjunto
	    \pre Existe un conjunto de torneos
	    \post Se imprime el valor de torneos total del conjunto
    */
    int num_torneos() const;

    /** @brief Comprueba si existe el torneo en el conjunto
	    \pre <em>nombre</em> es el nombre de un torneo
	    \post 1 si el torneo ya existe en el conjunto, 0 en caso contrario
    */ 
    bool existe_torneo(string nombre) const;

    //escritura y lectura inicial
    /** @brief Consulta e imprime los torneos en orden creciente lexicográfico
	    \pre Existe un conjunto de torneos ordenados en orden lexicográfico
	    \post Se ha impreso el conjunto de torneos de forma creciente y con su categoría
    */
    void listar_torneos(Cjt_categorias& c);

    /** @brief Hace la lectura inicial del conjunto torneos
       \pre <em>Cierto</em>
       \post Se ha leido el conjunto inicial de torneos con su categoria correspondiente
    */
    void lectura_ini_tor();


};
#endif

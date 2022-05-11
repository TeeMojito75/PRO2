/** @file Cjt_categorias.hh
    @brief Especificación de la clase Cjt_categorias
    */

#ifndef CJT_CATEGORIAS_HH
#define CJT_CATEGORIAS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif


using namespace std;

/** @class Cjt_categorias
    @brief Representa el conjunto de categorías de los torneos
    
    Dispone de atributos que definen las categorias
*/

/** @brief Struct que representa cada categoría
 */ 
struct categoria {
    string nombre;
    vector<int> puntuaciones;
};

class Cjt_categorias {

    private:
	/** @brief Vector de categorias, usado para trabajar con el conjunto de estas
	 */	
	vector<categoria> categorias;
	int k;

    public:
	//constructor
	/** @brief Constructora por defecto
	    \pre <em>cierto</em>
	    \post Se ha creado el conjunto de categorías
	*/
	Cjt_categorias();

	//escritura
	/** @brief Imprime las categorías en orden creciente de identificador
	    \pre Existe un conjunto de categorías
	    \post Se ha impreso el conjunto con sus identificadores, el nombre y la tabla de puntos
	*/
	void listar_categorias();

	//consultroa
	/** @brief Comprueba si la categoría existe ya en el conjunto
	    \pre <em>nombre</em> es el nombre de una categoría
	    \post 1 si la categoría ya existe, 0 en caso contrario
	 */ 
	bool existe_categoria(int cat);

	/** @brief Lee por consola los datos iniciales de las categorías y los almacena en un vector<categoria> categorias
	 	\pre <em>cierto</em> 
	 	\post Se ha guardado el vector privado vector<categoria> categorias con los elementos deseados  
	 */
	void lectura_ini_cat();

	/** @brief Consulta la categoría pasando su posición
	 * 	\pre cat >= 0
	 * 	\post Se ha devuelto el nombre de la categoría
	*/
	void consultar_categoria(int cat);

	/** @brief Retorna la puntuación por nivel
	 * 	\pre c<em>cat</em> identificador de una categoria
	 * 	\post Se ha devuelto la puntuación correspondiente
	*/
	int puntos(int cat, int nivel) const;
};
#endif


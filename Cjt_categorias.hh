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

/** @brief Estructura que define una categoria
    Cada categoría presenta un nombre y un vector con las puntuaciones
*/
struct categoria {
    string nombre;
    vector<int> puntuaciones;
};

/** @class Cjt_categorias
    @brief Representa el conjunto de categorías de los torneos
*/

class Cjt_categorias {

    private:
	/** @brief Vector de categorias, usado para trabajar con el conjunto de estas
	 * 	y un entero k que representa el número máximo de niveles
	 */	
	vector<categoria> categorias;
	int k;

    public:
	//constructora
	/** @brief Constructora por defecto
	    \pre <em>Cierto</em>
	    \post Se ha creado el conjunto de categorías
	*/
	Cjt_categorias();

	//escritura y lectura inicial
	/** @brief Imprime las categorías en orden creciente de identificador
	    \pre <em>Cierto</em>
	    \post Se ha impreso el conjunto con sus identificadores, el nombre y la tabla de puntos
	*/
	void listar_categorias();

	/** @brief Lee por consola los datos iniciales de las categorías y los almacena en un vector<categoria> categorias
	 	\pre <em>Cierto</em> 
	 	\post Se ha guardado el vector privado vector<categoria> categorias con los elementos deseados  
	*/
	void lectura_ini_cat();

	//consultoras
	/** @brief Comprueba si la categoría existe ya en el conjunto
	    \pre <em>cat</em> es el entero que representa el nivel de una categoría
	    \post Devuelve 1 si la categoría ya existe, 0 en caso contrario
	*/ 
	bool existe_categoria(int cat);

	/** @brief Consulta la categoría pasando su posición
	  	\pre <em>cat</em> es el entero que representa el nivel de una categoría
	  	\post Se ha devuelto el nombre de la categoría
	*/
	void consultar_categoria(int cat);

	/** @brief Devuelve la puntuación por nivel
	  	\pre <em>cat</em> identificador de una categoria y <em>nivel</em> los diferentes niveles de puntos
	  	\post Se ha devuelto la puntuación correspondiente
	*/
	int puntos(int cat, int nivel) const;
};
#endif


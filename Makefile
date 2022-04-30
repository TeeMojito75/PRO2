OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_jugadores.o Cjt_torneos.o Cjt_categorias.hh Jugador.hh Torneo.hh
	g++ -o program.exe program.o Cjt_jugadores.o Cjt_torneos.o Cjt_categorias.o Jugador.hh Torneo.hh

program.o: program.cc Cjt_jugadores.hh Cjt_torneos.hh Cjt_categorias.hh
	g++ -c program.cc $(OPCIONS)

Cjt_jugadores.o: Cjt_jugadores.cc Cjt_jugadores.hh Jugador.hh
	g++ -c Cjt_jugadores.cc $(OPCIONS)

Cjt_categorias.o: Cjt_categorias.cc Cjt_categorias.hh
	g++ -c Cjt_categorias.cc $(OPCIONS)

Cjt_torneos.o: Cjt_torneos.cc Cjt_torneos.hh Torneo.hh
	g++ -c Cjt_torneos.cc $(OPCIONS)
	

Torneo.o: Torneo.cc Torneo.hh Cjt_categorias.hh Cjt_jugadores.hh
	g++ -c Torneo.cc $(OPCIONS)

Jugador.o: Jugador.cc Jugador.hh
	g++ -c Jugador $(OPCIONS)

tar:
	tar -cvf practica.tar *.hh *.cc Makefile

clean:
	rm *.o
	rm *.exe
	rm practica.tar

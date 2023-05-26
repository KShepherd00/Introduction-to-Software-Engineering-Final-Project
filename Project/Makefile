final:	main.o Borc.o Control.o Dorc.o Dragon.o Fighter.o Harold.o Player.o Porc.o Timmy.o View.o
	g++ -o final main.o Borc.o Control.o Dorc.o Dragon.o Fighter.o Harold.o Player.o Porc.o Timmy.o View.o

main.o:	main.cc Control.h
	g++ -c main.cc

View.o:	View.cc View.h Display.h
	g++ -c View.cc

Borc.o:	Borc.cc Player.h
	g++ -c Borc.cc

Control.o:	Control.cc Control.h View.h Player.h
	g++ -c Control.cc

Dorc.o:	Dorc.cc	Player.h
	g++ -c Dorc.cc

Dragon.o:	Dragon.cc Player.h
	g++ -c Dragon.cc

Fighter.o:	Fighter.cc Player.h
	g++ -c Fighter.cc

Harold.o:	Harold.cc Player.h
	g++ -c Harold.cc

Player.o:	Player.cc Player.h
	g++ -c Player.cc

Porc.o:	Porc.cc Player.h
	g++ -c Porc.cc

Timmy.o:	Timmy.cc Player.h
	g++ -c Timmy.cc

clean:
	rm -f *.o final

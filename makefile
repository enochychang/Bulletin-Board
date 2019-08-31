a.out : main.o Message.o User.o BBoard.o
	g++ main.o Message.o User.o BBoard.o

main.o : main.cpp BBoard.h
	g++ -Wall -c main.cpp

Message.o : Message.cpp Message.h
	g++ -Wall -c Message.cpp

User.o : User.cpp User.h
	g++ -Wall -c User.cpp

BBoard.o : BBoard.cpp BBoard.h User.h Message.h
	g++ -Wall -c BBoard.cpp

clean :
	rm *.o a.out

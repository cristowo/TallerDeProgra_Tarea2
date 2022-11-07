FLAGS = -g -Wall

all: main test_Boat test_Container test_Solver

main: main.cpp Solver.o Container.o Boat.o
	g++ $(FLAGS) -o main Solver.o Container.o Boat.o main.cpp

Solver.o: Solver.cpp Solver.h
	g++ $(FLAGS) -c Solver.cpp

Container.o: Container.cpp Container.h
	g++ $(FLAGS) -c Container.cpp

Boat.o: Boat.cpp Boat.h
	g++ $(FLAGS) -c Boat.cpp

# TESTS

test_Container: test_Container.cpp Container.o
	g++ $(FLAGS) -o test_Container Container.o test_Container.cpp

test_Boat: test_Boat.cpp Boat.o Container.o
	g++ $(FLAGS) -o test_Boat Boat.o test_Boat.cpp Container.o

test_Solver: test_Solver.cpp Solver.o Container.o Boat.o
	g++ $(FLAGS) -o test_Solver Solver.o Container.o Boat.o test_Solver.cpp

clear:
	rm -f *.o main test_Container test_Boat test_Solver

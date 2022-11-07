#include "Container.h"

class Boat {
    public:
        // Constructor
        Boat();
        std::vector<Container> containers;
        // Añade un contenedor al barco
        void add(Container);
        // Retorna el tamaño del barco
        int size();
        // Retorna el contenedor en la posición pos
        Container getContainer(int container);
        // Ordena los contenedores de mayor a menor
        void ordenar();
        // Imprime el barco
        void print();
        // Compara dos barcos
        bool equals(Boat boat2);
};
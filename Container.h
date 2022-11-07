#include <iostream>
#include <vector>
#include <algorithm>
#include <stdbool.h>
#include <set>

class Container {
    public:
        // Constructor
        Container();
        std::multiset<int, std::greater<int>> container;
        // Añadide un item al contenedor
        void add(int);
        // Obtiene la suma del peso total de los items
        int sum();
        // Retorna el item en la posición pos
        int getItem(int pos);
        // Retorna un numero que indica la relacion entre los contenedores
        int compare(Container);
        // Retorna el tamaño del contenedor
        int size();
        // Imprime el contenedor
        void print();
};
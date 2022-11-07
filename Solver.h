#include "Boat.h"

class Solver {
    public:
        int capacidad;
        std::vector<int> items;
        Boat barcoFinal;
        //Constructor
        Solver();
        // Ordena los items de mayor a menor
        void ordenarItems();
        // Heuristica
        int heuristica();
        // Suma de los items
        int sumaPeso();
        // Busqueda binaria
        int solve();
        // Si se puede distribuir N items en K contenedores
        bool distribute(int k);
        // Llave para hash
        std::string generateKey(Boat &boat);
        // Eliminacion de duplicados
        void deleteDuplicates(std::vector<Boat> &boats);
};
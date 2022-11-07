#include "Solver.h"
#include <ctime>

int main(){
    srand(time(NULL));
    clock_t ti, tf;
    // Creamos un solver
    Solver S;
    // Pedimos la capacidad de los contenedores
    std::cout << "Ingrese la capacidad del los contenedores: ";
    std::cin >> S.capacidad;
    // Pedimos la cantidad de items
    int cantidad;
    std::cout << "Ingrese cantidad de items: ";
    std::cin >> cantidad;
    int maxpesoitem;
    while(true){
        std::cout << "Ingrese el peso maximo de los items: ";
        std::cin >> maxpesoitem;
        if(maxpesoitem <= S.capacidad){
            break;
        }
        std::cout << "El peso maximo de los items debe ser menor o igual a la capacidad de los contenedores" << std::endl;
    }
    // numeros random menores o iguales a la capacidad
    for(int i = 0; i < cantidad; i++){
        // S.items.push_back(rand() % S.capacidad + 1);
        S.items.push_back(rand() % maxpesoitem + 1);
    }
    ti = clock();
    // Solve
    S.solve();
    tf = clock();
    double tiempo = (tf - ti) / (double)CLOCKS_PER_SEC;
    std::cout << "Tiempo de ejecucion: " << tiempo << " segundos." <<std::endl;
    return 0;
}

    /*
    // Leemos la capacidad
    std::cout << "Ingrese la capacidad del los contenedores: ";
    std::cin >> S.capacidad;
    // Leemos los items
    std::cout << "Ingrese cantidad de items: ";
    int cantidad;
    std::cin >> cantidad;
    int item;
    for(int i = 0; i < cantidad; i++){
        std::cin >> item;
        S.items.push_back(item);
    }
    */
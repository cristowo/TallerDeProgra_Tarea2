#include "Boat.h"

/*
* Clase Boat, es un vector de contenedores
*/

/*
* Constructor
* Parametros: 
* Retornos: 
*/
Boat::Boat() {
    containers = std::vector<Container>();
}

/*
* Añade un contenedor al barco
* Parametros: Container
* Retornos: Void
*/
void Boat::add(Container container) {
    containers.push_back(container);
}

/*
* Retorna el tamaño del barco
* Parametros: 
* Retornos: Entero (tamaño del barco)
*/
int Boat::size() {
    return containers.size();
}

/*
* Retorna el contenedor en la posición pos
* Parametros: int posicion
* Retornos: Container
*/
Container Boat::getContainer(int container) {
    return containers[container];
}

/*
* Ordena los contenedores de mayor a menor
* Parametros:
* Retornos: Void
*/
void Boat::ordenar(){
    //odenar de mayor a menor
    for(int i = 0; i < (int)containers.size(); i++){
        for(int j = 0; j < (int)containers.size(); j++){
            // si el contenedor i es mayor que el contenedor j
            if(containers[i].compare(containers[j]) == 1){
                Container aux = containers[i];
                containers[i] = containers[j];
                containers[j] = aux;
            }
        }
    }
}

/*
* Printea el barco
* Parametros: 
* Retornos: Void
*/
void Boat::print() {
    std::cout << "Boat: " << std::endl;
    for (int i = 0; i < (int)containers.size(); i++) {
        std::cout << "Container " << i << ": " << std::endl;
        containers[i].print();
    }
}

/*
* Compara el barco con otro barco
* Parametros: Boat
* Retornos: Booleano
*/
bool Boat::equals(Boat boat2){
    this->ordenar();
    boat2.ordenar();
    for(int i = 0; i < (int)containers.size(); i++){
        if(containers[i].compare(boat2.getContainer(i)) != 0){
            return false;
        }
    }
    return true;
}
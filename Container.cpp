#include "Container.h"
/*
* Clase Container, encargado de almacenar los items
*/

/*
* Constructor
* Parametros: 
* Retornos:
*/
Container::Container() {
    container = std::multiset<int, std::greater<int>>();
}

/*
* Añadide un item al contenedor
* Parametros: Entero item
* Retornos: Void
*/
void Container::add(int value) {
    container.insert(value);
}

/*
* Obtiene la suma del peso total de los items
* Parametros: 
* Retornos:
*/
int Container::sum() {
    int sum = 0;
    for (auto it = container.begin(); it != container.end(); ++it) {
        sum += *it;
    }
    return sum;
}

/*
* Retorna el item en la posición pos
* Parametros: Entero pos
* Retornos: Entero
*/
int Container::getItem(int pos) {
    auto it = container.begin();
    std::advance(it, pos);
    return *it;
}

/*
* Retorna un numero que indica la relacion entre los contenedores
* Parametros: Container
* Retornos: int
*/
int Container::compare(Container container) {
    if(this->container == container.container){
        //iguales
        return 0;
    }else if(this->container > container.container){
        //mayor
        return 1;
    }else{
        //menor
        return -1;
    }
}

/*
* Retorna el tamaño del contenedor
* Parametros: 
* Retornos: Int
*/
int Container::size() {
    return container.size();
}

/*
* Imprime
* Parametros: 
* Retornos: Void
*/
void Container::print() {
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

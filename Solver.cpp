#include "Solver.h"

/*
* Clase Solver, encargado de la solución
*/

/*
* Constructor
* Parametros: 
* Retornos:
*/
Solver::Solver(){
    capacidad = 0;
    items = std::vector<int>();
    barcoFinal = Boat();
}

/*
* Ordena los items de mayor a menor
* Parametros: 
* Retornos: void
*/
void Solver::ordenarItems() {
    std::sort(items.begin(), items.end(), std::greater<int>());
}

/*
* Heuristica
* Teniendo los items de mayor a menor, los va agregando a cada container necesario
* Si no cae en uno, va al siguiente, si se acaban crea otro
* Parametros: vector de containers (aqui se guardara el resultado)
* Retornos: entero (número de containers utilizados)
*/
int Solver::heuristica(){
    // Ordenar los items de mayor a menor
    this->ordenarItems();

    // Boat Axiliar
    Boat B;
    // Creamos un contenedor
    Container C;
    // Agregamos el primer item al contenedor
    C.add(this->items[0]);
    // Agregamos el contenedor al barco
    B.add(C);
    // condicional de si pudo ingresar el item
    int cond;

    for (int i = 1; i < (int)this->items.size(); i++){
        cond = 0;
        //reocrremos boat
        for(int j = 0; j < (int)B.size(); j++){
            // si el item cabe en el contenedor
            if(B.getContainer(j).sum() + this->items[i] <= this->capacidad){
                // Agregamos el item al contenedor
                B.containers[j].add(this->items[i]);
                // Cambiamos la condicion
                cond = 1;
                // Salimos del for j
                break;
            }
        }
        // si no pudo ingresar el item
        if(cond == 0){
            // Creamos un contenedor
            Container C;
            // Agregamos el item al contenedor
            C.add(this->items[i]);
            // Agregamos el contenedor al barco
            B.add(C);
        }
    }
    // Guardamos el resultado en el barco
    this->barcoFinal = B;
    // Retornamos el numero de contenedores
    return B.size();
}

/*
* Suma el peso de todos los items
* Parametros: 
* Retornos:
*/
int Solver::sumaPeso(){
    int suma = 0;
    for(int i = 0; i < (int)items.size(); i++){
        suma += items[i];
    }
    return suma;
}

/*
* Busqueda Binaria
* Parametros: int flag(en evaluación)
* Retornos: Entero 0
*/
int Solver::solve(){
    int a, b, k;

    // Cuota superior
    a = this->heuristica();
    // Cuota inferior
    b = this->sumaPeso() / this->capacidad;

    std::cout << "Cuota superior: " << a << std::endl;
    std::cout << "Cuota inferior: " << b << std::endl;
    // Busqueda binaria
    while(a > b){
        k = (a + b)/2;
        if(distribute(k)){
            // Caso de sea verdadero
            // En caso de k == b, esto terminara
            // asi que no importa poner otro if
            a = k;
        }else{
            // Caso de sea falso
            // Si b != k, entonces b se iguala a k
            if(b != k){b = k;}
            //si b == k, entonces b se incrementa
            // y en el caso de que b++ == a, entonces se terminara
            else{b++;}
        }
    }
    // imprimir B
    this->barcoFinal.print();
    return a;
}

/*
* Ve si los items se pueden distribuir en la cantidad de contenedores dada
* Parametros: Entero k (cantidad de contenedores), Vector de contendores(aqui guardara el resultado) y Entero flag
* Retornos: Booleano
*/
bool Solver::distribute(int k){
    // Creamos parametros iniciales
    std::vector<std::vector<Boat>> G, Gaux;
    //Tabla hash
    std::unordered_map<std::string, Boat> H;
    std::vector<Boat> X, Xaux, Xaux2;
    Boat Y, Yaux;

    // se rellena el barco con contenedores vacios
    for(int i = 0; i < k; i++){
        Container C;
        Y.add(C);
    }
    // Agregamos a X el barco Y
    X.push_back(Y);
    // Agregamos a G el vector X
    G.push_back(X);

    // Muestra para entender
    // G -> {X1, X2...}                      -> G
    // X -> [Boat1, Boat2 ... Boatk]         -> G[j]
    // Y -> Boat                             -> G[j][k]
    // Boat -> [Container1, Container2...]   -> G[j][k].containers
    // Container -> [Item1, Item2...]        -> G[j][k].containers[l]

    std::string key;
    // Recorremos los items
    for(int i = 0; i < (int)items.size(); i++){                         // Por cada item
        for(int j = 0; j < (int)G.size(); j++){                         // Recorremos G por cada X
            for(int k = 0; k < (int)G[j].size(); k++){                  // Recorremos X por cada Y
                for(int l = 0; l < (int)G[j][k].size(); l++){           // Recorremos Y por cada container
                    if(G[j][k].getContainer(l).sum() + items[i] <= this->capacidad){
                        Yaux = G[j][k];
                        Yaux.containers[l].add(items[i]);
                        key = generateKey(Yaux);
                        auto ins = H.insert(make_pair(key, Yaux));
                        if(ins.second){
                            // auxiliar de Y
                            Yaux = G[j][k];
                            // Agregamos el nuevo item
                            Yaux.containers[l].add(items[i]);
                            // Agregamos Y a Xaux
                            Xaux.push_back(Yaux);
                        }
                    }
                }
            }
            
        }
        if(Xaux.size() > 0){
            // Eliminamos los repetidos
            //deleteDuplicates(Xaux);

            for(int m = 0; m < (int)Xaux.size(); m++){
                Xaux2.push_back(Xaux[m]);
                Gaux.push_back(Xaux2);
                Xaux2.clear();
            }
            Xaux.clear();
        }else{
            // Cuando no se puede agregar el item
            return false;
        }
        G = Gaux;
        Gaux.clear();
        //std::cout << "items: " << i << " Combinaciones: "<< G.size() <<std::endl;
    }
    // Guardamos el resultado en el barco
    this->barcoFinal = G[0][0];
    return true;
}

/*
* Gnera una llave para el hash
* Parametros: Boat B  
* Retornos: String
*/
std::string Solver::generateKey(Boat &boat){
    // barco auxiliar
    Boat B;
    B = boat;
    // ordenar los contenedores
    B.ordenar();

    std::string key = "";
    for(int i = 0; i < (int)B.size(); i++){
        for(int j = 0; j < (int)B.getContainer(i).size(); j++){
            key += std::to_string(B.getContainer(i).getItem(j)) + "-";
        }
        key += "|";
    }
    //std::cout << key << std::endl;
    return key;
}

/*
* Elimina duplicados
* Esta funcion quedo obsoleta luego de implementar el hash
* Parametros: vector de vector de cointainers 
* Retornos: void
*/
void Solver::deleteDuplicates(std::vector<Boat> &X){
    for(int i = 0; i < (int)X.size(); i++){
        for(int j = i+1; j < (int)X.size(); j++){
            if(X[i].equals(X[j])){
                X.erase(X.begin() + j);
                j--;
            }
        }
    }
}


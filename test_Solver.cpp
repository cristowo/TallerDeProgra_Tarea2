#include "Solver.h"

int main(){
    // Cualquiera de los 2 sirve
    /*
    Solver S1;
    S1.capacidad = 7;
    for(int i = 0; i < 10; i++){
        S1.items.push_back(rand() % 7 + 1);
    }
    S1.solve();
    */


    /*
    Solver S;
    S.capacidad = 100;
    S.items = {50, 3, 48, 53, 53, 4, 3, 41, 23, 20, 52, 49};
    S.solve();
    */
   
    /*
    Solver S2;
    S2.capacidad = 20;
    S2.items = {1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9};
    S2.solve();
    */


    Solver S3;
    S3.capacidad = 15;
    S3.items = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 10, 3, 4};
    S3.solve();

    return 0;
}
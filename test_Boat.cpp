#include "Boat.h"

int main(){
    Boat B;
    for(int i = 0; i < 3; i++){
        Container C;
        C.add(i+i);
        C.add(i+i+1);
        B.add(C);
    }
    std::cout << "B.size() = " << B.size() << std::endl;
    B.print();
    B.ordenar();
    B.print();
    return 0;
}
#include "Container.h"

int main(){
    Container C;
    for(int i = 0; i < 3; i++){
        C.add(i+i);
        C.add(i+i+1);
    }
    std::cout << "C.size() = " << C.size() << std::endl;
    std::cout << "C.getItem(1)= " << C.getItem(1) << std::endl;
    C.print();
    return 0;
}
#include <iostream>
#include "Singleton.h"
int main() {

    Singleton &s = Singleton::create();



    std::cout << "Hello, World!" << std::endl;
    return 0;
}

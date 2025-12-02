#include <iostream>
#include "tiere/Schwein.h"

class Metzger {
public:
    void schlachten(Tier *tier){
        std::cout << "Messer wetz" << std::endl;
    }
};
template<class T>
class Spediteur {
public:
    void fahren(T *Ware) {
        std::cout << "Wir fahren auf der Autobahn" << std::endl;
    }
};

int main() {

    Metzger metzger;
    Spediteur<Schwein> spediteur;
    Schwein piggy{"Miss piggy",10};
    piggy.addPigTooFatListener([&metzger](Schwein *s){metzger.schlachten(s);});
    piggy.addPigTooFatListener([&spediteur](Schwein *s){spediteur.fahren(s);});
    std::cout << "Hello, World!" << std::endl;

    for (int i = 0; i < 11; ++i) {
        piggy.fuettern();
    }
    return 0;
}

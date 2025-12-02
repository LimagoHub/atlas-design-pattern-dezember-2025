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
    piggy.addPigTooFatListener(
            std::bind(&Metzger::schlachten, &metzger, std::placeholders::_1)
    );

    piggy.addPigTooFatListener([&spediteur](Schwein *s){spediteur.fahren(s);});

    piggy.propertyChangedEvent.subscribe([](std::any,  const std::string& propertyName)-> void {
        std::cout << "Property " << propertyName << " hat sich geaendert\n";
    });

    std::cout << "Hello, World!" << std::endl;

    for (int i = 0; i < 11; ++i) {
        piggy.fuettern();
    }
    return 0;


}

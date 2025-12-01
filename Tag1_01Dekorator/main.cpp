#include <iostream>
#include <memory>
#include "client/Client.h"
#include "math/CalculatorFactory.h"


int main() {

    math::CalculatorFactory::setLogger(true);
    math::CalculatorFactory::setSecure(true);

    std::unique_ptr<math::Calculator> calculator = math::CalculatorFactory::create();


    client::Client client_{std::move(calculator)};

    client_.go();
    return 0;
}

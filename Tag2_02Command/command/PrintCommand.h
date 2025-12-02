//
// Created by JoachimWagner on 02.12.2025.
//

#pragma once
#include "AbstractCommand.h"
#include "../math/Calculator.h"
namespace command {


    class PrintCommand: public AbstractCommand{
    public:
        ~PrintCommand() override = default;

        auto execute() -> void override {
            math::Calculator::getInstance()->print();
        }
    };

} // command

//
// Created by JoachimWagner on 02.12.2025.
//

#pragma once
#include "AbstractCommand.h"
#include "../math/Calculator.h"
namespace command {

    class ClearCommand : public AbstractCommand{
    private:
        double value;
    public:
        auto undo() -> void override {
            math::Calculator::getInstance()->setMemory(value);
        }

        auto isQuery() -> bool override {
            return false;
        }

        auto execute() -> void override {
            value = math::Calculator::getInstance()->getMemory();
            math::Calculator::getInstance()->clear();
        }
    };

} // command

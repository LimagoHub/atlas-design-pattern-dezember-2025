//
// Created by JoachimWagner on 02.12.2025.
//

#pragma once
#include "Command.h"
#include "../math/Calculator.h"
namespace command {

    class AddCommand: public Command{
    private:
        double value;
    public:
        ~AddCommand() override = default;

        auto parse(const StringVector &tokens) -> void override {
            value = std::stod(tokens[1]);
        }

        auto execute() -> void override {
            math::Calculator::getInstance()->add(value);
        }

        auto undo() -> void override {
            math::Calculator::getInstance()->sub(value);
        }

        auto isQuery() -> bool override {
            return false;
        }
    };

} // command

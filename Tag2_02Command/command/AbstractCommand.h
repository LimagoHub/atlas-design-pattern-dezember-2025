//
// Created by JoachimWagner on 02.12.2025.
//

#pragma once
#include <stdexcept>
#include "Command.h"
namespace command {

    class AbstractCommand: public Command {
    public:
        ~AbstractCommand() override = default;

        auto parse(const StringVector &tokens) -> void override {
            // ok
        }



        auto undo() -> void override {
            throw std::logic_error{"Upps"};

        }

        auto isQuery() -> bool override {
            return true;
        }
    };

} // command

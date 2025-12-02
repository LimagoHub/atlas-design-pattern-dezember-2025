//
// Created by JoachimWagner on 02.12.2025.
//

#pragma once
#include <iostream>
#include <memory>
#include <stack>
#include "Command.h"
namespace command {
    using CommandPointer = std::shared_ptr<Command>;

    class CommandHistory {
        std::stack<CommandPointer> undoStack;
        std::stack<CommandPointer> redoStack;
    public:

        auto add(const CommandPointer &c )->void {
            if(c->isQuery()) return;
            // Insert your code here
            //Alle Redos loeschen
        }

        auto undo()->void {
            std::cout << "Can't undo" << std::endl;

        }

        auto redo()->void {
            std::cout << "Can't redo" << std::endl;
        }
    };

} // command

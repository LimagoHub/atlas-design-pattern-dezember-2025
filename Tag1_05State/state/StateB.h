//
// Created by JoachimWagner on 01.12.2025.
//

#pragma once
#include <iostream>
#include "AbstractState.h"

class StateB: public  AbstractState{
public:

    using AbstractState::AbstractState;
    void drucken() override {
        std::cout << "Hier druckt B" << std::endl;
    }

    void changeToA() override {
        getBusiness()->current = getBusiness()->stateA;
    }
};

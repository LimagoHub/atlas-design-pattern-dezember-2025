//
// Created by JoachimWagner on 01.12.2025.
//

#include "Business.h"
#include "state/StateA.h"
#include "state/StateB.h"

Business::Business():stateA{std::make_shared<StateA>(this)},
                     stateB{std::make_shared<StateB>(this)},
                     current(stateA){
}


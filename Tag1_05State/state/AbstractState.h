//
// Created by JoachimWagner on 01.12.2025.
//

#pragma once
#include <stdexcept>
#include "../Business.h"
#include "State.h"


class AbstractState : public State{
    Business * business;

protected:
    Business *getBusiness() const {
        return business;
    }

public:
    explicit AbstractState(Business *business) : business(business) {}

    ~AbstractState()  = default;

    void drucken() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToA() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }

    void changeToB() override {
        throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
    }


};

//
// Created by JoachimWagner on 03.12.2025.
//

#pragma once
#include "AbstractFileProcessor.h"

namespace processor {

    class CharacterCounter: public AbstractFileProcessor {
        int counter;
    public:
        void init() override {
            counter = 0;
        }

        void process(char c) override {
            counter ++;
        }

        void dispose() override {
            std::cout << "Counter" << ": " << counter << std::endl;
        }
    };

} // processor

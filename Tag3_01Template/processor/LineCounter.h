//
// Created by JoachimWagner on 03.12.2025.
//

#pragma once
#include "AbstractFileProcessor.h"
namespace processor {

    class LineCounter :public AbstractFileProcessor{
        int counter;
    public:
        void init() override {
            counter = 0;
        }

        void process(char c) override {
            if(c == '\n') counter ++;
        }

        void dispose() override {
            std::cout << typeid(*this).name() << ": " << counter << std::endl;
        }
    };

} // processor

//
// Created by JoachimWagner on 03.12.2025.
//

#pragma once

#include <string>
#include <fstream>
#include <iostream>

namespace processor {

    class AbstractFileProcessor {
    public:
        void run(std::string filename) { // Darf nicht ueberschrieben werden
            std::fstream fin(filename, std::ios::in);
            if(! fin.is_open()) {
                std::cout << "Fehler beim Oeffnen von " << filename << std::endl;
                return;
            }
            int ch;
            init();
            while( EOF != (ch = fin.get())) {
                process((char) ch);
            }
            dispose();
            fin.close();
        }

        virtual void init() { // Kann ueberschrieben werden
            // ok
        }

        virtual void process(char c) = 0; // Muss ueberschrieben werden

        virtual void dispose() {// Kann ueberschrieben werden
            // ok
        }
    };

} // processor

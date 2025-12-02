//
// Created by JoachimWagner on 02.12.2025.
//

#pragma once
#include <string>
#include <ostream>
#include <vector>
#include <functional>
#include "Tier.h"

class Schwein: public Tier {

    inline static const unsigned MAX_WEIGHT{20};

    std::vector<std::function<void(Schwein *)>> listeners;

    std::string name;
    int gewicht;
    void firePigTooFatEvent() {
        for (const auto &listener: listeners) {
            listener(this);
        }
    }

    inline void setGewicht(int gewicht) {
        Schwein::gewicht = gewicht;
        if (gewicht > MAX_WEIGHT) firePigTooFatEvent();
    }
public:
    Schwein(const std::string &name, int gewicht=10) : name(name), gewicht(gewicht) {}


    void addPigTooFatListener(const std::function<void(Schwein *)> &listener) {
        listeners.emplace_back(listener);
    }


    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Schwein::name = name;
    }

    int getGewicht() const {
        return gewicht;
    }

    void fuettern() {
        setGewicht(getGewicht() +1);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "Schwein " << " name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }
};

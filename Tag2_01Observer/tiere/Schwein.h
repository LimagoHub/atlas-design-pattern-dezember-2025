//
// Created by JoachimWagner on 02.12.2025.
//

#pragma once
#include <string>
#include <ostream>
#include <vector>
#include <functional>
#include "Tier.h"
#include "../propertychanged/PropertyChangedEvent.h"

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
        if(Schwein::gewicht == gewicht) return;

        Schwein::gewicht = gewicht;
        if (gewicht > MAX_WEIGHT) firePigTooFatEvent();
        propertyChangedEvent.fire(this, "gewicht");
    }
public:
    PropertyChangedEvent propertyChangedEvent;

    Schwein(const std::string &name, int gewicht=10) : name(name), gewicht(gewicht) {}


    void addPigTooFatListener(const std::function<void(Schwein *)> &listener) {
        listeners.emplace_back(listener);
    }


    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        if(Schwein::name == name) return;
        Schwein::name = name;
        propertyChangedEvent.fire(this, "name");
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

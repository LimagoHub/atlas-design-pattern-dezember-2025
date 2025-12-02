//
// Created by JoachimWagner on 02.12.2025.
//

#pragma once
#include <functional>
#include <vector>
#include <any>
#include <string>

class PropertyChangedEvent {
public:
    using Handler = std::function<void(std::any sender, const std::string& propertyName)>;

    // Listener registrieren
    void subscribe(Handler handler) {
        handlers_.emplace_back(std::move(handler));
    }

    // Event feuern
    void fire(std::any sender, const std::string& propertyName) {
        for (auto& h : handlers_) {
            h(sender, propertyName);
        }
    }

private:
    std::vector<Handler> handlers_;
};

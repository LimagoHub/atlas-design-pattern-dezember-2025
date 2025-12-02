#include <iostream>
#include <functional>
#include <vector>
#include <any>
#include <string>

class Event
{
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



#include <iostream>

class Person
{
public:
    Event PropertyChanged;

    Person(std::string name, int age)
            : name_(std::move(name)), age_(age) {}

    const std::string& name() const { return name_; }
    int age() const { return age_; }

    void setName(const std::string& newName) {
        if (name_ != newName) {
            name_ = newName;
            // Event feuern: sender = *this, propertyName = "name"
            PropertyChanged.fire(std::any(this), "name");
        }
    }

    void setAge(int newAge) {
        if (age_ != newAge) {
            age_ = newAge;
            // Event feuern: sender = *this, propertyName = "age"
            PropertyChanged.fire(std::any(this), "age");
        }
    }

private:
    std::string name_;
    int age_;
};


void ereignisHandler (Person * p, const std::string& propertyName) {
    std::cout << "Property '" << propertyName
              << "' hat sich geaendert bei Person "
              << p->name() << "\n";

    if (propertyName == "age") {
        std::cout << "Neues Alter: " << p->age() << "\n";
    } else if (propertyName == "name") {
        std::cout << "Neuer Name: " << p->name() << "\n";
    }
}


int main()
{
    Person p{"Alice", 30};

    // Listener registrieren
    p.PropertyChanged.subscribe(
            [](std::any sender, const std::string& propertyName) {
                // Wir *wissen*, dass der Sender ein Person* ist:
                auto personPtr = std::any_cast<Person*>(sender);
                ereignisHandler(personPtr, propertyName);

            }
    );
    // Änderungen auslösen
    p.setName("Bob");
    p.setAge(31);

    return 0;
}
#include "Animal.h"
#include <string>

// Dog class
class Dog : public Animal {
public:
    Dog(const std::string& name, const Location& location);

    void printDetails() const override;
    char getInitial() const override;
    void step() override;
    void stop() override;
    void move() override;
    
};
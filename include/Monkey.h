#include "Animal.h"
#include <string>

// Monkey class
class Monkey : public Animal {
public:
    Monkey(const std::string& name, const Location& location);
    void printDetails() const override;
    char getInitial() const override;
    void step() override;
    void stop() override;
    void move() override;
    void turnVertically() override;
    void turnHorizontally() override;
};
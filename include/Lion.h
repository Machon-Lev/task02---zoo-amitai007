#ifndef LION_H
#define LION_H

#include "Animal.h"
#include <string>

class Lion : public Animal {
public:
    Lion(const std::string& name, const Location& location);
    void printDetails() const override;
    char getInitial() const override;
    void step() override;
    void stop() override;
    void move() override;
};

#endif /* LION_H */

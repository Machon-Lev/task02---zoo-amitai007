#include "Dog.h"
#include "Animal.h"

#include <iostream>

// Dog class

    Dog::Dog(const std::string& name, const Location& location) : Animal(name, location) {}

    void Dog::printDetails() const{
        std::cout << "Name: " << _name << " " << "Type: " << "Dog " << "Location: " << _location << std::endl;
    }

    char Dog::getInitial() const{
        return 'D';
    }

    void Dog::step(){
        // Run three steps forward and then one step back
        for (int i = 0; i < 3; i++) {
            _location._col += 1;
        }
        _location._col -= 1;

        if (_location._row < 0) {
            _location._row = 0;
        }
        if (_location._row > 19) {
            _location._row = 19;
        }
        if (_location._col < 0) {
            _location._col = 0;
        }
        if (_location._col > 39) {
            _location._col = 39;
        }
    }

    void Dog::stop(){
        // Do nothing
    }

    void Dog::move(){
        // Reset direction
        _location._row = _location._row / 2;
        _location._col = _location._col / 2;
    }


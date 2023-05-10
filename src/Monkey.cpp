// Monkey class
#include "Monkey.h"
#include "Animal.h"
#include <iostream>
#include <string>
#include <random>


  Monkey::Monkey(const std::string& name, const Location& location) : Animal(name, location) {}

  void Monkey::printDetails() const{
      std::cout << "Name: " << _name << " " << "Type: " << "Monkey " << "Location: " << _location << std::endl;
  }

  char Monkey::getInitial() const{
    return 'M';
  }

  void Monkey::step(){
    
    // Randomly jump one or two squares in any direction
    int step = rand() % 2 + 1;
    int direction = rand() % 4;
    if (direction == 0) {
      _location._row += step;
    } else if (direction == 1) {
      _location._row -= step;
    } else if (direction == 2) {
      _location._col += step;
    } else {
      _location._col -= step;
    }

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

  void Monkey::stop(){
    // Do nothing
  }

  void Monkey::move(){
    // Reset direction
    _location._row = _location._row / 2;
    _location._col = _location._col / 2;
  }

  void Monkey::turnVertically(){
    // Do nothing
  }

  void Monkey::turnHorizontally(){
    // Do nothing
  }

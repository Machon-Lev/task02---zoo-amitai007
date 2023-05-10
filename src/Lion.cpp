#include "Animal.h"
#include "Lion.h"
#include <iostream>

// Lion class

	Lion::Lion(const std::string& name, const Location& location) : Animal(name, location) {}

	void Lion::printDetails() const{
		std::cout << "Name: " << _name << " " << "Type: " << "Lion " << "Location: " << _location << std::endl;
	}

	char Lion::getInitial() const{
		return 'L';
	}

	void Lion::step(){

		if (_location._row % 2 == 0) {
			_location._col += 2;
		}
		else {
			_location._col -= 2;
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

	void Lion::stop(){
		// Do nothing
	}

	void Lion::move(){
		// Reset direction
		_location._row = _location._row / 2;
		_location._col = _location._col / 2;
	}




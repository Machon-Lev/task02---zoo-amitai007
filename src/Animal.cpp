#include "Animal.h"
#include <iostream>
#include <string>

Animal::Animal() {}


Animal::Animal(std::string name, Location location)
{
	_name = name;
	_location = location;
	_is_moving = true;
}

Location Animal::getLocation() const
{
	return _location;
}

void Animal::stop()
{
	_is_moving = false;
}

void Animal::move()
{
	_is_moving = true;
}

void Animal::turnVertically()
{
}

void Animal::turnHorizontally()
{
}

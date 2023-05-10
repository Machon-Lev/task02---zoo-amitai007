#ifndef ANIMAL_H
#define ANIMAL_H

#include "Location.h"
#include <string>

class Animal {
public:
	Animal(std::string _name, Location _location);
	// Pure virtual functions
	virtual void printDetails() const = 0;
	virtual char getInitial() const = 0;
	Location getLocation() const;
	virtual void step() = 0;

	virtual void stop();
	virtual void move();
	virtual void turnVertically();
	virtual void turnHorizontally();

protected:
	std::string _name;
	bool _is_moving;
	Location _location;

private:
	Animal();

};

#endif // ANIMAL_H
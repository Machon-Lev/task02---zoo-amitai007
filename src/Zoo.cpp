

#include <iostream>
#include <vector>
#include <random>

#include "Animal.h"
#include "Location.h"
#include "Zoo.h"
#include "Dog.h"
#include "Monkey.h"
#include "Lion.h"

int ROWS = 20;
int COLUMNS = 40;


// Constructor
Zoo::Zoo() {
	m_exit = false;
	addAnimal("D", "Toto");
	addAnimal("M", "Rafiki");
	addAnimal("L", "Simba");
	addAnimal("L", "Mufasa");
}

// Destructor
Zoo::~Zoo() {
	for (auto animal : m_animals) {
		delete animal;
	}
}

// Methods
void Zoo::run() {

	while (!m_exit) {
		// Print the map of the zoo
		printMap();

		// Print the list of animals
		printList();

		// Read commands from the user
		std::string command;
		std::cout << "Please Enter a command:" << std::endl;
		std::cin >> command;

		if (command == "stop") {
			// Stop the specified animal
			int animalIndex;
			std::cout << "Enter a Animal index to stop:" << std::endl;
			std::cin >> animalIndex;
			stopAnimal(animalIndex);
		}
		else if (command == "move") {
			// Move the specified animal
			int animalIndex;
			std::cin >> animalIndex;
			moveAnimal(animalIndex);
		}
		else if (command == "create") {
			// Create another animal
			std::string type;
			std::string name;
			std::cin >> type >> name;
			addAnimal(type, name);
		}
		else if (command == "del") {
			// Delete the specified animal
			int animalIndex;
			std::cin >> animalIndex;
			removeAnimal(animalIndex);
		}
		else if (command == "delAll") {
			// Delete all animals of the specified type
			char type;
			std::cin >> type;
			removeAllOfAnimalType(type);
		}
		else if (command == "help") {
			// Print help text
			printHelp();
		}
		else if (command == ".") {
			// Move all animals forward one step
			updateAnimals();
		}
		else if (command == "exit") {
			// Exit the program
			m_exit = true;
		}
		else {
			// Invalid command
			std::cout << "Invalid command." << std::endl;
		}
	}
}

// Private methods
void Zoo::printMap() const {
	std::cout << "Zoo Map:" << std::endl;

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			bool isCellFull = false;
			for (auto& animal : m_animals)
			{
				if (!isCellFull && animal->getLocation()._row == r && animal->getLocation()._col == c)
				{
					// the first animal we findwill be printed
					std::cout << animal->getInitial() << " ";
					isCellFull = true;
				}
			}
			// if no animal in the cell - print '-'
			if (!isCellFull)
			{
				std::cout << "- ";
			}
		}
		std::cout << "\n";
	}
}

void Zoo::printList() const {
	//std::cout << "List of animals:" << std::endl;
	//for (int i = 0; i < m_animals.size(); i++) {
	//    m_animals[i]->printDetails();
	//    std::cout << std::endl; // Add std::endl after each animal
	//}

	int index = 0;
	std::cout << "Zoo list:\n";
	for (auto& animal : m_animals)
	{
		std::cout << index << ") ";
		animal->printDetails();
		index++;
	}
}

int RandomGen(int lower_bound, int upper_bound)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(lower_bound, upper_bound);
	return dist(gen);
}

void Zoo::addAnimal(const std::string& type, const std::string& name) {
	// Create a new animal of the specified type and name
	Animal* animal = nullptr;

	if (type == "L") {
		animal = new Lion(name, Location(RandomGen(0,19), RandomGen(0,39)));
	}
	else if (type == "M") {
		animal = new Monkey(name, Location(RandomGen(0, 19), RandomGen(0, 39)));
	}
	else if (type == "D") {
		animal = new Dog(name, Location(RandomGen(0, 19), RandomGen(0, 39)));
	}
	else {
		// Invalid type
		std::cout << "Invalid type." << std::endl;
		return;
	}

	// Add the animal to the list of animals
	m_animals.push_back(animal);
}

void Zoo::removeAnimal(int animalIndex) {
	// Check if the specified animal number is valid
	if (animalIndex < 0 || animalIndex >= m_animals.size()) {
		// Invalid animal number
		std::cout << "Invalid animal number." << std::endl;
		return;
	}

	// Remove the animal from the list of animals
	delete m_animals[animalIndex];
	m_animals.erase(m_animals.begin() + animalIndex);
}

void Zoo::removeAllOfAnimalType(const char& type) {
	// Iterate over the list of animals
	for (int i = 0; i < m_animals.size(); i++) {
		// If the current animal is of the specified type, remove it
		if (m_animals[i]->getInitial() == type) {
			delete m_animals[i];
			m_animals.erase(m_animals.begin() + i);
			i--;
		}
	}
}

void Zoo::stopAnimal(int animalIndex) {
	// Check if the specified animal number is valid
	if (animalIndex < 0 || animalIndex >= m_animals.size()) {
		// Invalid animal number
		std::cout << "Invalid animal number." << std::endl;
		return;
	}

	// Stop the animal
	m_animals[animalIndex]->stop();
}

void Zoo::moveAnimal(int animalIndex) {
	// Check if the specified animal number is valid
	if (animalIndex < 0 || animalIndex >= m_animals.size()) {
		// Invalid animal number
		std::cout << "Invalid animal number." << std::endl;
		return;
	}

	// Move the animal
	m_animals[animalIndex]->move();
}

void Zoo::printHelp() const {
	std::cout << "Available commands:" << std::endl;
	std::cout << "stop <animal number> - Stop the specified animal" << std::endl;
	std::cout << "move <animal number> - Move the specified animal" << std::endl;
	std::cout << "create <type> <name> - Create another animal" << std::endl;
	std::cout << "del <animal number> - Delete the specified animal" << std::endl;
	std::cout << "delAll <type> - Delete all animals of the specified type" << std::endl;
	std::cout << "help - Print this help text" << std::endl;
	std::cout << "exit - Exit the program" << std::endl;
}

void Zoo::updateAnimals() {
	// Iterate over the list of animals
	for (auto animal : m_animals) {
		// Update the animal's position
		animal->step();
	}
}

void Zoo::clearScreen() const {
	std::cout << std::string(50, '\n');
}

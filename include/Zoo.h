#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include "Animal.h"
#include "Location.h"

class Zoo {
public:
    // Constructor
    Zoo();

    // Destructor
    ~Zoo();

    // Methods
    void run();

private:
    // Private methods
    void printMap() const;
    void printList() const;
    void addAnimal(const std::string& type, const std::string& name);
    void removeAnimal(int animalNum);
    void removeAllOfAnimalType(const char& type);
    void stopAnimal(int animalNum);
    void moveAnimal(int animalNum);
    void printHelp() const;
    void updateAnimals();
    void clearScreen() const;

    // Private data members
    std::vector<Animal*> m_animals;
    std::vector<Animal*> m_map[20][40];
    bool m_exit;
};

#endif // ZOO_H

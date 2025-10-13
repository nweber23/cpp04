#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal: default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "WrongAnimal: copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "WrongAnimal: copy assignment" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: destructor" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal: generic wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
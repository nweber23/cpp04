#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog: default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog: copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	Animal::operator=(other);
	std::cout << "Dog: copy assignment" << std::endl;
	return *this;
}
Dog::~Dog() {
	std::cout << "Dog: destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog: Woof" << std::endl;
}

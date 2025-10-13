#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat: default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat: copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	Animal::operator=(other);
	std::cout << "Cat: copy assignment" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat: destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat: Meow" << std::endl;
}
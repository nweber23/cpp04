#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : brain(new Brain()) {
	type = "Cat";
	std::cout << "Cat: default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat: copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		if (brain) {
			*brain = *other.brain;
		} else {
			brain = new Brain(*other.brain);
		}
	}
	std::cout << "Cat: copy assignment" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat: destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat: Meow" << std::endl;
}

void Cat::setBrainIdea(int index, const std::string& idea) {
	if (brain) {
		brain->setIdea(index, idea);
	}
}

std::string Cat::getBrainIdea(int index) const {
	if (brain) {
		return brain->getIdea(index);
	}
	return "";
}
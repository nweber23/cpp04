#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : brain(new Brain()) {
	type = "Dog";
	std::cout << "Dog: default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog: copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		if (brain) {
			*brain = *other.brain;
		} else {
			brain = new Brain(*other.brain);
		}
	}
	std::cout << "Dog: copy assignment" << std::endl;
	return *this;
}
Dog::~Dog() {
	delete brain;
	std::cout << "Dog: destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog: Woof" << std::endl;
}

void Dog::setBrainIdea(int index, const std::string& idea) {
	if (brain) {
		brain->setIdea(index, idea);
	}
}

std::string Dog::getBrainIdea(int index) const {
	if (brain) {
		return brain->getIdea(index);
	}
	return "";
}

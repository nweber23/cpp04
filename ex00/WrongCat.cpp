#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat: default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat: copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	WrongAnimal::operator=(other);
	std::cout << "WrongCat: copy assignment" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: destructor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat: Meow" << std::endl;
}
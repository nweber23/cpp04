#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Basic polymorphism test ===\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "\n=== Array polymorphism test ===\n";
	std::vector<Animal*> zoo;
	for (int k = 0; k < 3; ++k) zoo.push_back(new Dog());
	for (int k = 0; k < 2; ++k) zoo.push_back(new Cat());
	for (size_t k = 0; k < zoo.size(); ++k) {
		std::cout << "[" << k << "] type=" << zoo[k]->getType() << " -> ";
		zoo[k]->makeSound();
	}
	for (Animal* a : zoo) delete a;
	std::cout << "\n=== Copy & assignment tests ===\n";
	Dog d1;
	{
		Dog d2 = d1;
		d2.makeSound();
	}
	Dog d3;
	d3 = d1;
	std::cout << "\n=== WrongAnimal demonstration ===\n";
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	std::cout << "wcat type: " << wcat->getType() << "\n";
	wcat->makeSound();
	delete wmeta;
	delete wcat;
	return 0;
}
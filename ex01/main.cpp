#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "=== Brain ideas deep-copy tests ===\n";
	Dog d1;
	d1.setBrainIdea(0, "Chase ball");
	Dog d2 = d1;
	d1.setBrainIdea(0, "Chew bone");
	std::cout << "Dog d1 idea[0]: " << d1.getBrainIdea(0) << "\n";
	std::cout << "Dog d2 idea[0]: " << d2.getBrainIdea(0) << "\n";
	Cat c1;
	c1.setBrainIdea(42, "Nap on keyboard");
	Cat c2;
	c2 = c1;
	c1.setBrainIdea(42, "Knock cup");
	std::cout << "Cat c1 idea[42]: " << c1.getBrainIdea(42) << "\n";
	std::cout << "Cat c2 idea[42]: " << c2.getBrainIdea(42) << "\n";

	return 0;
}
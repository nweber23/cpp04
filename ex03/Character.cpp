#include "Character.hpp"

AMateria* Character::droppedMaterias[1024] = { nullptr };
size_t Character::droppedCount = 0;

Character::Character(std::string const & name) : name(name) {
	for (size_t i = 0; i < 4; ++i) {
		inventory[i] = nullptr;
	}
}

Character::~Character() {
	clearInventory();
	for (size_t i = 0; i < droppedCount; ++i) {
		delete droppedMaterias[i];
	}
	droppedCount = 0;
}

Character::Character(Character const & other) : name(other.name) {
	for (size_t i = 0; i < 4; ++i) {
		inventory[i] = nullptr;
	}
	copyInventory(other);
}

Character & Character::operator=(Character const & other) {
	if (this != &other) {
		name = other.name;
		clearInventory();
		copyInventory(other);
	}
	return *this;
}

std::string const & Character::getName() const {
	return name;
}

void Character::clearInventory() {
	for (size_t i = 0; i < 4; ++i) {
		if (inventory[i]) {
			delete inventory[i];
			inventory[i] = nullptr;
		}
	}
}

void Character::copyInventory(const Character& other) {
	for (size_t i = 0; i < 4; ++i) {
		if (other.inventory[i]) {
			inventory[i] = other.inventory[i]->clone();
		} else {
			inventory[i] = nullptr;
		}
	}
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (size_t i = 0; i < 4; ++i) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || !inventory[idx])
		return;
	if (droppedCount < 1024) {
		droppedMaterias[droppedCount++] = inventory[idx];
	}
	inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || !inventory[idx])
		return;
	inventory[idx]->use(target);
}

void Character::cleanDropped() {
	for (size_t i = 0; i < droppedCount; ++i) {
		delete droppedMaterias[i];
		droppedMaterias[i] = nullptr;
	}
	droppedCount = 0;
}
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < 4; ++i) {
		materiaSlots[i] = nullptr;
	}
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4; ++i) {
		if (materiaSlots[i]) {
			delete materiaSlots[i];
		}
	}
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	for (size_t i = 0; i < 4; ++i) {
		if (other.materiaSlots[i]) {
			materiaSlots[i] = other.materiaSlots[i]->clone();
		} else {
			materiaSlots[i] = nullptr;
		}
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other) {
	if (this != &other) {
		for (size_t i = 0; i < 4; ++i) {
			if (materiaSlots[i]) {
				delete materiaSlots[i];
			}
			if (other.materiaSlots[i]) {
				materiaSlots[i] = other.materiaSlots[i]->clone();
			} else {
				materiaSlots[i] = nullptr;
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		return;
	}
	for (size_t i = 0; i < 4; ++i) {
		if (!materiaSlots[i]) {
			materiaSlots[i] = m;
			return;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < 4; ++i) {
		if (materiaSlots[i] && materiaSlots[i]->getType() == type) {
			return materiaSlots[i]->clone();
		}
	}
	return nullptr;
}
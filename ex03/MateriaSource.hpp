#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Amateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* materiaSlots[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(MateriaSource const & other);
		MateriaSource & operator=(MateriaSource const & other);

		virtual void learnMateria(AMateria* m) override;
		virtual AMateria* createMateria(std::string const & type) override;
};

#endif
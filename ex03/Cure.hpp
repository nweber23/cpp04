#ifndef CURE_HPP
#define CURE_HPP

#include "Amateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure();
		virtual ~Cure();
		Cure(Cure const & other);
		Cure & operator=(Cure const & other);

		virtual AMateria* clone() const override;
		virtual void use(ICharacter& target) override;
};

#endif
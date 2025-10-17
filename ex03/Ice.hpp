#ifndef ICE_HPP
#define ICE_HPP

#include "Amateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		Ice();
		virtual ~Ice();
		Ice(Ice const & other);
		Ice & operator=(Ice const & other);

		virtual AMateria* clone() const override;
		virtual void use(ICharacter& target) override;
};

#endif
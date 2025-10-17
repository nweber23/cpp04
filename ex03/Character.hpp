#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Amateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria* inventory[4];
		static AMateria* droppedMaterias[1024];
		static size_t droppedCount;

		void clearInventory();
		void copyInventory(const Character& other);
	public:
		Character(std::string const & name);
		virtual ~Character();
		Character(Character const & other);
		Character & operator=(Character const & other);

		std::string const & getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;

		static void cleanDropped();
};

#endif
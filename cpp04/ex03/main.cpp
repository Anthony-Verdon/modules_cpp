/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:48:57 by averdon           #+#    #+#             */
/*   Updated: 2023/05/16 11:26:53 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
	{
		std::cout << "[TEST SUBJECT]\n";
		IMateriaSource* Materias = new MateriaSource();
		Materias->learnMateria(new Ice());
		Materias->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = Materias->createMateria("ice");
		me->equip(tmp);
		tmp = Materias->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete Materias;
		std::cout << "\n";
	}
	{
		std::cout << "[TEST MATERIA]\n";
		ICharacter *Ybbob = new Character("Ybbob");
		const AMateria *ice = new Ice();
		ice->getType();
		ice->use(*Ybbob);
		AMateria *clone = ice->clone();
		delete (ice);
		clone->getType();
		clone->use(*Ybbob);
		delete(clone);
		AMateria *cure = new Cure();
		cure->getType();
		cure->use(*Ybbob);
		clone = cure->clone();
		delete (cure);
		clone->getType();
		clone->use(*Ybbob);
		AMateria *clone2 = clone->clone();
		delete(clone);
		clone2->getType();
		clone2->use(*Ybbob);
		delete (clone2);
		delete (Ybbob);
		std::cout << "\n";
	}
	{
		std::cout << "[TEST CHARACTER]\n";
		IMateriaSource* Materias = new MateriaSource();
		ICharacter *Ybbob = new Character("Ybbob");
		ICharacter *Bobby = new Character("Bobby");
		AMateria *ice = new Ice();
		AMateria *ice2 = new Ice();
		AMateria *cure = new Cure();
		AMateria *cure2 = new Cure();
		AMateria *cure3 = new Cure();
		Ybbob->equip(ice);
		Ybbob->equip(ice2);
		Ybbob->equip(cure);
		Ybbob->equip(cure2);
		Ybbob->equip(cure3);
		AMateria* tmp;
		tmp = Materias->createMateria("Unknown");
		Ybbob->unequip(0);
		Ybbob->equip(tmp);
		Ybbob->equip(ice);
		for (int i = 0; i < 4; i++)
			Ybbob->use(i, *Bobby);
		delete Materias;
		delete Ybbob;
		delete Bobby;
		delete cure3;
		std::cout << "\n";
	}
	{
		std::cout << "[TEST MATERIASOURCE]\n";
		IMateriaSource* Materias = new MateriaSource();
		AMateria* tmp;
		AMateria *ice = new Ice();
		AMateria *cure = new Cure();
		tmp = Materias->createMateria("ice");
		tmp = Materias->createMateria("cure");
		Materias->learnMateria(ice);
		Materias->learnMateria(cure);
		tmp = Materias->createMateria("ice");
		delete tmp;
		tmp = Materias->createMateria("cure");
		delete tmp;
		delete Materias;
		std::cout << "\n";
	}
	{
		ICharacter *a = new Character("a");
		ICharacter *b = new Character("b");
		AMateria *ice = new Ice();
		a->equip(ice);
		b->equip(ice);
		delete a;
		delete b;
	}
	return 0;
}

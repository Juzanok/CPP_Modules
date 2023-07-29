/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:12:15 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 16:27:45 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
# define YELLOW	"\033[0m\033[93m"
# define RESET	"\033[0m"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << YELLOW << "[ Test 1 : subject + using empty inventory slots test ]" << RESET << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	std::cout << std::endl << YELLOW << "[ Test 2 : equip full inventory test ]" << RESET << std::endl;
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << std::endl << YELLOW << "[ Test 3 : unequip test ]" << RESET << std::endl;
	me->unequip(2);
	me->unequip(3);
	me->unequip(3);
	me->unequip(4);

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	me->equip(src->createMateria("ice"));
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	std::cout << std::endl << YELLOW << "[ Test 4 : trying to equip unknown materia test ]" << RESET << std::endl;
	me->equip(src->createMateria("asfbi8asbfiabd"));
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:51:00 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/26 16:30:38 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ScavTrap scav("scav");
	FragTrap frag("frag");

	std::cout << std::endl << scav << frag << std::endl;
	std::cout << YELLOW << "[ Guard gate / High fives guys test ]" << RESET << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	std::cout << std::endl;

	std::cout << YELLOW << "[ Attack/Repair tests ]" << RESET << std::endl;
	scav.attack("frag");
	frag.takeDamage(scav.getAttackDamage());
	std::cout << scav << frag << std::endl;

	frag.beRepaired(scav.getAttackDamage());
	frag.attack("scav");
	scav.takeDamage(frag.getAttackDamage());
	std::cout << scav << frag << std::endl;

	frag.takeDamage(101);
	frag.attack("some random dude");
	std::cout << scav << frag << std::endl;

	return 0;
}
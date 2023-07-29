/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:51:00 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/27 03:52:00 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap diam("diam");

	std::cout << std::endl << diam << std::endl;

	std::cout << YELLOW << "[ Guard gate test ]" << RESET << std::endl;
	diam.guardGate();

	std::cout << std::endl << YELLOW << "[ High fives guys test ]" << RESET << std::endl;
	diam.highFivesGuys();

	std::cout << std::endl << YELLOW << "[ Who am I test ]" << RESET << std::endl;
	diam.whoAmI();

	std::cout << std::endl << YELLOW << "[ Attack test ]" << RESET << std::endl;
	diam.attack("some random dude");
	std::cout << diam << std::endl;

	std::cout << YELLOW << "[ Take damage test ]" << RESET << std::endl;
	diam.takeDamage(99);
	std::cout << diam << std::endl;

	std::cout << YELLOW << "[ Be repaired test ]" << RESET << std::endl;
	diam.beRepaired(49);
	std::cout << diam << std::endl;

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:51:00 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/30 12:25:30 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap clap("clap");
	ScavTrap scav("scav");

	std::cout << std::endl << clap << scav << std::endl;
	std::cout << YELLOW << "[ Guard gate test ]" << RESET << std::endl;
	scav.guardGate();
	std::cout << std::endl;


	std::cout << YELLOW << "[ Attack/Repair tests ]" << RESET << std::endl;
	clap.attack("scav");
	scav.takeDamage(clap.getAttackDamage());
	scav.beRepaired(clap.getAttackDamage());
	std::cout << clap << scav << std::endl;

	scav.attack("clap");
	clap.takeDamage(scav.getAttackDamage());
	clap.beRepaired(scav.getAttackDamage());
	std::cout << clap << scav << std::endl;

	return 0;
}
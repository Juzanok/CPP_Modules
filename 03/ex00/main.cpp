/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:51:00 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/27 03:30:14 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap claptrap("Pirate");

	std::cout << std::endl << claptrap << std::endl;

	std::cout << YELLOW << "[ Attack test ]" << RESET << std::endl;
	claptrap.attack("the philosopher");
	std::cout << claptrap << std::endl;


	std::cout << YELLOW << "[ Take damage test ]" << RESET << std::endl;
	claptrap.takeDamage(7);
	std::cout << claptrap << std::endl;


	std::cout << YELLOW << "[ Be repaired test ]" << RESET << std::endl;
	claptrap.beRepaired(7);
	std::cout << claptrap << std::endl;


	std::cout << YELLOW << "[ Take too much damage test ]" << RESET << std::endl;
	claptrap.takeDamage(11);
	claptrap.attack("the philosopher");
	claptrap.beRepaired(11);
	claptrap.takeDamage(1);

	std::cout << claptrap << std::endl;

	return 0;
}
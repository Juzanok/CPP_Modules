/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:25:43 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/27 03:50:20 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("") {
	std::cout << "[ ScavTrap default constructor called ]" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "[ ScavTrap string constructor called ]" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap() {
 	std::cout << "[ ScavTrap copy constructor called ]" << std::endl;
 	*this = scavtrap;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "[ ScavTrap destructor called ]" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap) {
	std::cout << "[ ScavTrap copy assignment operator called ]" << std::endl;
	name = scavtrap.name;
	hitPoints = scavtrap.hitPoints;
	energyPoints = scavtrap.energyPoints;
	attackDamage = scavtrap.attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
			  << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " can’t attack " << target << ", because it has no hit points or energy points left" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << name << " has entered Gate keeper mode" << std::endl;
}

std::ostream& operator<<(std::ostream & stream, const ScavTrap& scavtrap)
{
	stream	<< MAGENTA << scavtrap.getName() << " | " << "HP: " << scavtrap.getHitPoints() << " | " << "EP: " << scavtrap.getEnergyPoints() << " | " << "AD: " << scavtrap.getAttackDamage() << RESET <<  std::endl;
	return (stream);
}
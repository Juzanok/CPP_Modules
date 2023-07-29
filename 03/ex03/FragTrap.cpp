/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:13:49 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/27 03:50:51 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("") {
	std::cout << "[ FragTrap default constructor called ]" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "[ FragTrap string constructor called ]" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap() {
	std::cout << "[ FragTrap copy constructor called ]" << std::endl;
	*this = fragtrap;
}

FragTrap::~FragTrap(void) {
	std::cout << "[ FragTrap destructor called ]" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
	std::cout << "[ FragTrap copy assignment operator called ]" << std::endl;
	name = fragtrap.name;
	hitPoints = fragtrap.hitPoints;
	energyPoints = fragtrap.energyPoints;
	attackDamage = fragtrap.attackDamage;
	return (*this);
}

void	FragTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "FragTrap " << name << " attacks " << target << ", causing "
			  << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << name << " can’t attack " << target << ", because it has no hit points or energy points left" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " : High five guys!" << std::endl;
}

std::ostream& operator<<(std::ostream & stream, const FragTrap& fragtrap)
{
	stream	<< GREEN << fragtrap.getName() << " | " << "HP: " << fragtrap.getHitPoints() << " | " << "EP: " << fragtrap.getEnergyPoints() << " | " << "AD: " << fragtrap.getAttackDamage() << RESET <<  std::endl;
	return (stream);
}
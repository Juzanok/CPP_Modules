/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:40:43 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/27 03:41:22 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name") {
	std::cout << "[ DiamondTrap default constructor called ]" << std::endl;
	this->name = "";
	this->FragTrap::hitPoints = 100;
	this->ScavTrap::energyPoints = 50;
	this->FragTrap::attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name") {
	std::cout << "[ DiamondTrap string constructor called ]" << std::endl;
	this->name = name;
	this->FragTrap::hitPoints = 100;
	this->ScavTrap::energyPoints = 50;
	this->FragTrap::attackDamage = 30;
}

DiamondTrap::DiamondTrap(const ScavTrap &diamondtrap) {
	std::cout << "[ DiamondTrap copy constructor called ]" << std::endl;
	*this = diamondtrap;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "[ DiamondTrap destructor called ]" << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap) {
	std::cout << "[ DiamondTrap copy assignment operator called ]" << std::endl;
	if (this == &diamondtrap)
		return (*this);
	name = diamondtrap.name;
	hitPoints = diamondtrap.hitPoints;
	energyPoints = diamondtrap.energyPoints;
	attackDamage = diamondtrap.attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap : DiamondTrap name = " << this->name << std::endl;
	std::cout << "DiamondTrap : ClapTrap name = " << this->ClapTrap::name << std::endl; 
}

std::string DiamondTrap::getDiamondName(void) const{
	return (this->name);
}

std::ostream& operator<<(std::ostream & stream, const DiamondTrap& diamondtrap) {
	stream	<< RED << diamondtrap.getDiamondName() << " | " << "HP: " << diamondtrap.getHitPoints() << " | " << "EP: " << diamondtrap.getEnergyPoints() << " | " << "AD: " << diamondtrap.getAttackDamage() << RESET <<  std::endl;
	return (stream);
}
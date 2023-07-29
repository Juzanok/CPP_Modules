/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:50:56 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/30 12:19:16 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "[ ClapTrap default constructor called ]" << std::endl;
	this->name = "";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string &name){
	std::cout << "[ ClapTrap string constructor called ]" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap){
	std::cout << "[ ClapTrap copy constructor called ]" << std::endl;
	*this = claptrap;
}

ClapTrap::~ClapTrap(void){
	std::cout << "[ ClapTrap destructor called ]" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
	std::cout << "[ ClapTrap copy assignment operator called ]" << std::endl;
	this->name = claptrap.name;
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " can’t attack " << target << ", because it has no hit points or energy points left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repaired itself and got " << amount << " hit points back" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " can’t repair itself, because it has no hit points or energy points left" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0) {
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage" << std::endl;
		if (hitPoints >= amount)
			hitPoints -= amount;
		else
			hitPoints = 0;
	}
	else 
		std::cout << "ClapTrap " << name << " can't take any more damage, because it doesn't have any hit points left" << std::endl;
}

std::string const &ClapTrap::getName(void) const{
	return (this->name);
}

int	ClapTrap::getHitPoints(void) const{
	return (hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const{
	return (energyPoints);
}

int	ClapTrap::getAttackDamage(void) const{
	return (attackDamage);
}

std::ostream& operator<<(std::ostream & stream, const ClapTrap& claptrap) {
	stream	<< CYAN << claptrap.getName() << " | " << "HP: " << claptrap.getHitPoints() << " | " << "EP: " << claptrap.getEnergyPoints() << " | " << "AD: " << claptrap.getAttackDamage() << RESET <<  std::endl;
	return (stream);
}

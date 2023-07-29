/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:00:59 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 16:25:56 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : name("") {
	// std::cout << "[ Character default constructor called ]" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	storage_idx = 0;
}

Character::Character(const std::string &name) : name(name) {
	// std::cout << "[ Character string constructor called ]" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	storage_idx = 0;
}

Character::Character(const Character &copy) {
	// std::cout << "[ Character copy constructor called ]" << std::endl;
	*this = copy;
}

Character::~Character(void) {
	// std::cout << "[ Character destructor called ]" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete (this->inventory[i]);
	}
	for (int i = 0; i < storage_idx; i++) {
		delete (unequip_storage[i]);
	}
}

Character &Character::operator=(const Character &copy) {
	// std::cout << "[ Character copy assignment operator called ]" << std::endl;
	if (this == &copy)
		return (*this);
	this->name = copy.name;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete (this->inventory[i]);
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return (*this);
}

std::string	const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	int i = 0;

	while (this->inventory[i] != NULL && i < 4)
		i++;
	if (i < 4 && m != NULL) {
		this->inventory[i] = m;
	}
	else {
		if (m != NULL) {
			std::cout << "Unable to equip this materia, inventory is already full" << std::endl;
			delete (m);
		}
		else
			std::cout << "Unable to equip a materia that is a null pointer" << std::endl;
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	unequip_storage[storage_idx] = inventory[idx];
	storage_idx++;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Inventory slots range from 0 to 3, slot " << idx << " is invalid" << std::endl;
		return ;
	}
	if (this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
	else
		std::cout << "Unable to use : inventory slot " << idx << " is empty" << std::endl;
}



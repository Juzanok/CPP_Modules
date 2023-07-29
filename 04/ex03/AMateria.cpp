/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:44:21 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 16:03:10 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	// std::cout << "[ AMateria default constructor called ]" << std::endl;
	this->type = "Unknown";
}

AMateria::AMateria(std::string const & type) {
	// std::cout << "[ AMateria string constructor called ]" << std::endl;
	this->type = type; 
}

AMateria::AMateria(const AMateria &copy) {
	*this = copy;
}

AMateria::~AMateria() {
	// std::cout << "[ AMateria destructor called ]" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &copy) {
	// std::cout << "[ AMateria copy assignment operator called ]" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
	return (*this);
}

std::string const &AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter &target) {
	std::cout << "* unknown effect to " << target.getName() << " *" << std::endl;
}

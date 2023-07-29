/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:51:45 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 16:00:34 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	// std::cout << "[ Cure default constructor called ]" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy) {
	// std::cout << "[ Cure copy constructor called ]" << std::endl;
	*this = copy;
}

Cure::~Cure(void) {
	// std::cout << "[ Cure destructor called ]" << std::endl;
}

Cure &Cure::operator=(const Cure &copy) {
	// std::cout << "[ Cure copy assignment operator called ]" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
	return (*this);
}

Cure *Cure::clone( void ) const {
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:59:04 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 16:01:14 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	// std::cout << "[ Ice default constructor called ]" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
	// std::cout << "[ Ice copy constructor called ]" << std::endl;
	*this = copy;
}

Ice::~Ice(void) {
	// std::cout << "[ Ice destructor called ]" << std::endl;
}

Ice &Ice::operator=(const Ice &copy) {
	// std::cout << "[ Ice copy assignment operator called ]" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
	return (*this);
}

Ice *Ice::clone( void ) const {
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:09:30 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 13:23:32 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	std::cout << "[ WrongAnimal default constructor called ]" << std::endl;
	this->type = "Wrong unknown animal";
}

WrongAnimal::WrongAnimal( const WrongAnimal &copy ) {
	std::cout << "[ WrongAnimal copy constructor called ]" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "[ WrongAnimal destructor called ]" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "[ WrongAnimal copy assignment operator called ]" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return (*this);
}

std::string WrongAnimal::getType() const {
	return (this->type);
}

void WrongAnimal::makeSound( void ) const {
	std::cout << type << " : uga buga uga buga !!!" << std::endl;
}
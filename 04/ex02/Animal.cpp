/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:15:10 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 15:58:46 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) {
	std::cout << "[ Animal default constructor called ]" << std::endl;
	this->type = "Unknown animal";
}

Animal::Animal( const Animal &copy ) {
	std::cout << "[ Animal copy constructor called ]" << std::endl;
	*this = copy;
}

Animal::~Animal( void ) {
	std::cout << "[ Animal destructor called ]" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this == &other)
		return *this;
	this->type = other.getType();
	return (*this);
}

std::string Animal::getType() const {
	return (this->type);
}

void Animal::makeSound( void ) const {
	std::cout << type << " : uga buga uga buga !!!" << std::endl;
}
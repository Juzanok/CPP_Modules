/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:29:15 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 13:29:58 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "[ Dog default constructor called ]" << std::endl;
	this->type = "Dog";
}

Dog::Dog( const Dog &copy ): Animal() {
	std::cout << "[ Dog copy constructor called ]" << std::endl;
	*this = copy;
}

Dog::~Dog( void ) {
	std::cout << "[ Dog destructor called ]" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "[ Dog copy assignment operator called ]" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return (*this);
}

void Dog::makeSound( void ) const {
	std::cout << type << " : woof woof!" << std::endl;
}
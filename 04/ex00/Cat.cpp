/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:46 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 13:29:02 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) {
	std::cout << "[ Cat default constructor called ]" << std::endl;
	this->type = "Cat";
}

Cat::Cat( const Cat &copy ): Animal() {
	std::cout << "[ Cat copy constructor called ]" << std::endl;
	*this = copy;
}

Cat::~Cat( void ) {
	std::cout << "[ Cat destructor called ]" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "[ Cat copy assignment operator called ]" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return (*this);
}

void Cat::makeSound( void ) const {
	std::cout << type << " : meeeeeeeow!" << std::endl;
}
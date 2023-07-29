/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:59:03 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 13:31:39 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
	std::cout << "[ WrongCat default constructor called ]" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &copy ): WrongAnimal() {
	std::cout << "[ WrongCat copy constructor called ]" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat( void ) {
	std::cout << "[ WrongCat destructor called ]" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "[ WrongCat copy assignment operator called ]" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return (*this);
}

void WrongCat::makeSound( void ) const {
	std::cout << type << " : meeeeeeeow!" << std::endl;
}
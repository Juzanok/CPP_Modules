/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:29:15 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 15:59:34 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "[ Dog default constructor called ]" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog( const Dog &copy ): Animal() {
	std::cout << "[ Dog copy constructor called ]" << std::endl;
	*this = copy;
}

Dog::~Dog( void ) {
	delete (this->brain);
	std::cout << "[ Dog destructor called ]" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this == &other)
		return (*this);
	this->type = other.getType();
	this->brain = new Brain(*other.brain);
	return (*this);
}

void Dog::makeSound( void ) const {
	std::cout << type << " : woof woof!" << std::endl;
}

void Dog::set_idea(const std::string &idea, int i) {
	this->brain->setIdeas(idea, i);
}

void Dog::print_idea(int i) {
	if (i < 0 || i > 99) {
		std::cout << "invalid idea index" << std::endl;
		return ;
	}
	
	std::string *ideas = this->brain->getIdeas();
	std::cout << ideas[i] << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:46 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 15:58:36 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) {
	std::cout << "[ Cat default constructor called ]" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat( const Cat &copy ): Animal() {
	std::cout << "[ Cat copy constructor called ]" << std::endl;
	*this = copy;
}

Cat::~Cat( void ) {
	delete (this->brain);
	std::cout << "[ Cat destructor called ]" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this == &other)
		return (*this);
	this->type = other.getType();
	this->brain = new Brain(*other.brain);
	return (*this);
}

void Cat::makeSound( void ) const {
	std::cout << type << " : meeeeeeeow!" << std::endl;
}

void Cat::set_idea(const std::string &idea, int i) {
	this->brain->setIdeas(idea, i);
}

void Cat::print_idea(int i) {
	if (i < 0 || i > 99) {
		std::cout << "invalid idea index" << std::endl;
		return ;
	}
	
	std::string *ideas = this->brain->getIdeas();
	std::cout << ideas[i] << std::endl;
}
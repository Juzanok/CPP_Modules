/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:40:47 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 15:58:41 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "[ Brain default constructor called ]" << std::endl;
}

Brain::Brain( const Brain &copy ) {
	std::cout << "[ Brain copy constructor called ]" << std::endl;
	*this = copy;
}

Brain::~Brain(void) {
	std::cout << "[ Brain destructor called ]" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

std::string *Brain::getIdeas() {
	return (this->ideas);
}

void Brain::setIdeas(std::string const &idea, int i) {
	if (i < 0 || i > 99) {
		std::cout << "invalid idea index" << std::endl;
		return ;
	}
	this->ideas[i] = idea;
}
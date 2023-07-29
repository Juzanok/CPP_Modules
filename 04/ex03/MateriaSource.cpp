/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:52:35 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 16:18:01 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	// std::cout << "[ MateriaSource default constructor called ]" << std::endl;
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	// std::cout << "[ MateriaSource copy constructor called ]" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource(void) {
	// std::cout << "[ MateriaSource detructor called ]" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materia[i])
			delete (this->materia[i]);
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	// std::cout << "[ MateriaSource copy assignment operator called ]" << std::endl;
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 4; i++) {
		if (this->materia[i])
			delete (this->materia[i]);
		if (copy.materia[i])
			this->materia[i] = copy.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* src) {
	int i = 0;

	while (this->materia[i] != NULL && i < 4)
		i++;
	if (i != 4) {
		this->materia[i] = src;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] && materia[i]->getType() == type)
			return (this->materia[i]->clone()); 
	}
	if (type != "")
		std::cout << "Materia " << type << " is unknown, it can not be created" << std::endl;
	else
		std::cout << "Can not create a materia with an empty type" << std::endl;
	return (0);
}
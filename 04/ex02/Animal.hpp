/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:49:03 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 16:06:20 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{

protected:

	std::string type; 

public:

	Animal(void);
	Animal(const Animal &copy);
	virtual ~Animal(void);

	Animal & operator=(const Animal &other);

	std::string getType() const; 
	virtual void makeSound() const = 0;
};

#endif
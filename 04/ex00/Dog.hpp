/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:11:30 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 13:46:58 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal{
public:

	Dog(void);
	Dog(const Dog &copy);
	~Dog(void);

	Dog & operator=(const Dog &copy);

	virtual void makeSound() const;
};

#endif
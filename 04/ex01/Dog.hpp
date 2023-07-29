/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:11:30 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 15:52:12 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
private:
	Brain*	brain;
public:

	Dog(void);
	Dog(const Dog &copy);
	~Dog(void);

	Dog & operator=(const Dog &copy);

	virtual void makeSound() const;
	void set_idea(const std::string &idea, int i);
	void print_idea(int i);
};

#endif
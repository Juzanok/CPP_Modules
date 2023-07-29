/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:09:57 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 15:55:04 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
private:
	Brain*	brain;
public:

	Cat(void);
	Cat(const Cat &copy);
	~Cat(void);

	Cat & operator=(const Cat &copy);

	virtual void makeSound() const;
	void set_idea(const std::string &idea, int i);
	void print_idea(int i);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:09:57 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 13:28:53 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal{
public:

	Cat(void);
	Cat(const Cat &copy);
	~Cat(void);

	Cat & operator=(const Cat &copy);

	virtual void makeSound() const;
};

#endif
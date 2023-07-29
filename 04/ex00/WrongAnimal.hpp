/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:08:18 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 13:47:29 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{

protected:

	std::string type; 

public:

	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &copy);
	virtual ~WrongAnimal(void);

	WrongAnimal & operator=(const WrongAnimal &other);

	std::string getType() const; 
	void makeSound() const;
};

#endif
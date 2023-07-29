/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:59:06 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 13:31:23 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:

	WrongCat(void);
	WrongCat(const WrongCat &copy);
	~WrongCat(void);

	WrongCat & operator=(const WrongCat &copy);

	void makeSound() const;
};

#endif
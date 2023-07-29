/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:05:09 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 15:59:56 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure &copy);
	~Cure(void);

	Cure &operator=(const Cure &copy);

	Cure	*clone( void ) const;
	virtual void use(ICharacter &target);
};

#endif
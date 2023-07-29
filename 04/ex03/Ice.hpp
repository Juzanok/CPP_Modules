/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:02:34 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 16:00:47 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice &copy);
	~Ice(void);

	Ice &operator=(const Ice &copy);

	Ice	*clone(void) const;
	virtual void use(ICharacter &target);
};

#endif
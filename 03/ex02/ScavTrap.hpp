/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:25:40 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/27 03:27:45 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:

	ScavTrap(void);
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &scavtrap);
	~ScavTrap(void);

	ScavTrap & operator=(const ScavTrap &scavtrap);

	void	attack(const std::string& target);
	void	guardGate(void);
};

std::ostream& operator<<(std::ostream & stream, const ScavTrap& scavtrap);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:34:12 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/26 16:35:15 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string name;

public:

	DiamondTrap(void);
	DiamondTrap(std::string const &name);
	DiamondTrap(const ScavTrap &diamondtrap);
	~DiamondTrap(void);

	DiamondTrap & operator=(const DiamondTrap &diamondtrap);

	void	attack(const std::string& target);
	void	whoAmI();

	std::string getDiamondName(void) const;
};

std::ostream& operator<<(std::ostream & stream, const DiamondTrap& diamondtrap);

#endif
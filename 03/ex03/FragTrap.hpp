/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:12:09 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/27 03:28:19 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
public:

	FragTrap(void);
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &fragtrap);
	~FragTrap(void);

	FragTrap & operator=(const FragTrap &fragtrap);

	void	attack(const std::string& target);
	void	highFivesGuys(void);
};

std::ostream& operator<<(std::ostream & stream, const FragTrap& fragtrap);

#endif
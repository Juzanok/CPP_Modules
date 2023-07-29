/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:13:20 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/29 20:09:35 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Weapon.hpp"

class HumanA{
private:
		std::string name;
		Weapon &weapon;
public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA( void );
		void attack( void );
};

#endif
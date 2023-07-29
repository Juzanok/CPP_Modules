/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:13:36 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/29 20:23:07 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Weapon.hpp"

class HumanB{
private:
		std::string name;
		Weapon *weapon;
public:
		HumanB(std::string name);
		~HumanB( void );
		void setWeapon(Weapon &weapon);
		void attack();
};

#endif
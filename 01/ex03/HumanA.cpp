/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:30:31 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/10 13:11:18 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA( void ) {}

void HumanA::attack( void ){
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
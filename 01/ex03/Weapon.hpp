/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:11:37 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/10 13:07:52 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Weapon{
private:
	std::string type;
public:
	Weapon(std::string type);
	~Weapon( void );
	const std::string &getType( void );
	void setType(std::string type);
};

#endif
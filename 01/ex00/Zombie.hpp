/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:37:51 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/12 11:49:16 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Zombie{
private:
		std::string name;
public:
		void announce( void );
		Zombie(std::string name);
		~Zombie( void );
};

Zombie*	newZombie( std::string name );
void 	randomChump( std::string name );

#endif
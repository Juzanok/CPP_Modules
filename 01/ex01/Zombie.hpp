/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:37:51 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/12 13:15:15 by jkarosas         ###   ########.fr       */
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
		~Zombie( void );
		void announce( void );
		void set_name( std::string name );
};

Zombie* zombieHorde( int N, std::string name );
void	announceHorde(Zombie *horde, int size);

#endif
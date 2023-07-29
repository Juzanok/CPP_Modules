/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:46:27 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/10 12:57:53 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		horde[i].set_name(name);
		horde[i].announce();
	}
	return horde;
}
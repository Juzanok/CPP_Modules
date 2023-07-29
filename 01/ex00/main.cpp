/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:37:41 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/10 12:39:55 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	{
		std::cout << "[ Test 1 ]" << std::endl;
		Zombie Tom("Tom");
		Tom.announce();
	}
	{
		std::cout << "[ Test 2 ]" << std::endl;
		Zombie *Nick = newZombie("Nick");
		Nick->announce();
		delete Nick;
	}
	{
		std::cout << "[ Test 3 ]" << std::endl;
		randomChump("Charles");
	}

	return (0);
}

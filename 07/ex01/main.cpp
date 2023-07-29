/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:08 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/24 01:25:24 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
	int 	len = 5;
	int 	num[len] = {1, 2, 3, 4, 5};
	char	letter[len] = {'h', 'e', 'l', 'l', 'o'};

	std::cout << YELLOW << "[ printEndl, add_one, ft_toupper functions on char array using iter ]" << RESET << std::endl;
	iter(letter, len, printEndl);
	std::cout << std::endl;

	iter(letter, len, subtract_one);
	iter(letter, len, printEndl);
	std::cout << std::endl;

	iter(letter, len, add_one);
	iter(letter, len, printEndl);
	std::cout << std::endl;

	iter(letter, len, ft_toupper);
	iter(letter, len, printEndl);
	std::cout << std::endl << std::endl;


	std::cout << YELLOW << "[ printEndl, add_one functions on int array using iter ]" << RESET << std::endl;
	iter(num, len, printEndl);
	std::cout << std::endl;

	iter(num, len, add_one);
	iter(num, len, printEndl);
	std::cout << std::endl << std::endl;
	

	std::cout << YELLOW << "[ Class test ]" << RESET << std::endl;
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);

	return (0);	
}
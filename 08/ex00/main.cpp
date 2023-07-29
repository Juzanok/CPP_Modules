/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:06:07 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/28 14:47:12 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	std::vector<int>	vector;
	std::list<int>		list;
	std::deque<int>		deque;

	fillContainer(vector, 10);
	fillContainer(list, 10);
	fillContainer(deque, 10);
	
	std::cout << YELLOW << "[ Vector test ]" << RESET << std::endl;
	try {
		std::cout << *easyfind(vector, 9) << std::endl;
		std::cout << *easyfind(vector, 10) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << std::endl << YELLOW << "[ Deque test ]" << RESET << std::endl;
	try {
		std::cout << *easyfind(deque, 6) << std::endl;
		std::cout << *easyfind(deque, 11) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	
	std::cout << std::endl << YELLOW << "[ List test ]" << RESET << std::endl;
	try {
		std::cout << *easyfind(list, 0) << std::endl;
		std::cout << *easyfind(list, 1) << std::endl;
		std::cout << *easyfind(list, 2) << std::endl;
		std::cout << *easyfind(list, 3) << std::endl;
		std::cout << *easyfind(list, 4) << std::endl;
		std::cout << *easyfind(list, 5) << std::endl;
		std::cout << *easyfind(list, 6) << std::endl;
		std::cout << *easyfind(list, 7) << std::endl;
		std::cout << *easyfind(list, 8) << std::endl;
		std::cout << *easyfind(list, 9) << std::endl;
		std::cout << *easyfind(list, 10) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
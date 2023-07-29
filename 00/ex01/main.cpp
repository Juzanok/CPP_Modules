/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:45:23 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/10 15:14:22 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	std::string command;
	PhoneBook	book;

	while (command != "EXIT")
	{
		std::cout << "# Command (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, command);
		if (command == "ADD")
			book.exec_add();
		else if (command == "SEARCH")
		{
			book.exec_search();
			std::cin.ignore(1, '\n');
		}
		else if (command != "EXIT")
			std::cout << "*** " << command << " : Unknown command ***" << std::endl;
	}
	return (0);
}
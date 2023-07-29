/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:33:46 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 02:01:51 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

# define YELLOW	"\033[0m\033[93m"
# define RESET	"\033[0m"

int	main(void)
{
	std::cout << YELLOW << "[ TEST 1 ]" << RESET <<  std::endl;
	try {
		Bureaucrat	tommy = Bureaucrat("Tommy", 150);
		std::cout << tommy;
		tommy.incrementGrade(50);
		std::cout << tommy;
		tommy.decrementGrade(48);
		std::cout << tommy;
		tommy.decrementGrade(5);
		std::cout << tommy;
		tommy.decrementGrade(54);
		std::cout << tommy;
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << YELLOW << "[ TEST 2 ]" << RESET <<  std::endl;
	try {
		Bureaucrat	john = Bureaucrat("John", 1);
		std::cout << john;
		john.decrementGrade(19);
		std::cout << john;
		john.incrementGrade(5);
		std::cout << john;
		john.incrementGrade(20);
		std::cout << john;
		john.incrementGrade(200);
		std::cout << john;
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << YELLOW << "[ TEST 3 ]" << RESET <<  std::endl;
	try {
		Bureaucrat	fin = Bureaucrat("Fin", 151);
		std::cout << fin;
		fin.incrementGrade(56);
		std::cout << fin;
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << YELLOW << "[ TEST 4 ]" << RESET <<  std::endl;
	try {
		Bureaucrat	arthur = Bureaucrat("Arthur", 0);
		std::cout << arthur;
		arthur.decrementGrade(80);
		std::cout << arthur;
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}

	return 0;
}
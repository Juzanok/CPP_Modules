/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:33:46 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 12:47:03 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << YELLOW << "[ TEST 1 ]" << RESET <<  std::endl;
	try {
		Bureaucrat	tommy = Bureaucrat("Tommy", 10);
		Form		form1 = Form("#11111", 20, 1);
		Form		form2 = Form("#22222", 5, 1);

		std::cout << tommy << form1 << form2 << std::endl;

		tommy.signForm(form1);
		tommy.signForm(form2);
		std::cout << tommy << form1 << form2 << std::endl;
		
		tommy.signForm(form1);
		std::cout << tommy << form1 << form2 << std::endl;
		
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << YELLOW << "[ TEST 2 ]" << RESET <<  std::endl;
	try {
		Form		form = Form("#9191520", 50, 1);
		Bureaucrat	tommy = Bureaucrat("Tommy", 10);
		Bureaucrat	johny = Bureaucrat("Johny", 120);

		std::cout << tommy << johny << form << std::endl;

		form.beSigned(johny);
		std::cout << form;
		form.beSigned(tommy);
		std::cout << form;
		
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << YELLOW << "[ TEST 3 ]" << RESET <<  std::endl;
	try {
		Form		form = Form("#9191520", 50, 1);
		Bureaucrat	tommy = Bureaucrat("Tommy", 10);

		std::cout << tommy << form << std::endl;

		form.beSigned(tommy);
		std::cout << form;
		
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << YELLOW << "[ TEST 4 ]" << RESET <<  std::endl;
	try {
		Form		form = Form("#7733", 151, 1);
		Bureaucrat	tommy = Bureaucrat("Tommy", 10);

		std::cout << tommy << form << std::endl;
		form.beSigned(tommy);

	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << YELLOW << "[ TEST 5 ]" << RESET <<  std::endl;
	try {
		Form		form = Form("#7733", 149, 0);
		Bureaucrat	tommy = Bureaucrat("Tommy", 10);

		std::cout << tommy << form << std::endl;
		form.beSigned(tommy);

	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

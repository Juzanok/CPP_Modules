/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:33:46 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/07 15:26:43 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	president("President", 1);
	Bureaucrat	tommy("Tommy", 71);
	Bureaucrat	johny("Johny", 142);

	Form	*shrubberyCreationForm = new ShrubberyCreationForm("Trees_Org");
	Form	*robotomyRequestForm = new RobotomyRequestForm("Robo_Org");
	Form	*presidentialPardonForm = new PresidentialPardonForm("Turkey_Org");



	std::cout << YELLOW << "[ TEST 1 ]" << RESET <<  std::endl;
	try {
		shrubberyCreationForm->execute(tommy);
		shrubberyCreationForm->beSigned(tommy);
		shrubberyCreationForm->execute(tommy);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << YELLOW << "[ TEST 2 ]" << RESET <<  std::endl;
	try {
		tommy.signForm(*shrubberyCreationForm);
		shrubberyCreationForm->execute(tommy);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << YELLOW << "[ TEST 3 ]" << RESET <<  std::endl;
	try {
		robotomyRequestForm->beSigned(tommy);
		robotomyRequestForm->execute(president);
		robotomyRequestForm->execute(president);
		robotomyRequestForm->execute(president);
		robotomyRequestForm->execute(president);
		robotomyRequestForm->execute(president);
		robotomyRequestForm->execute(president);
		robotomyRequestForm->execute(president);
		robotomyRequestForm->execute(president);
		president.executeForm(*robotomyRequestForm);
		tommy.executeForm(*robotomyRequestForm);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << YELLOW << "[ TEST 4 ]" << RESET <<  std::endl;
	try {
		president.signForm(*presidentialPardonForm);
		president.executeForm(*presidentialPardonForm);
		presidentialPardonForm->execute(president);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;

	delete shrubberyCreationForm;
	delete robotomyRequestForm;
	delete presidentialPardonForm;

	return 0;
}
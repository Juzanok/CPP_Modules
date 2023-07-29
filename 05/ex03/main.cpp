/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:33:46 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 13:59:37 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	Bureaucrat president("president", 1);
	Intern someRandomIntern;
	Form *scf, *rrf, *ppf;

	scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

	std::cout << std::endl;
	
	president.signForm(*scf);
	president.signForm(*rrf);
	president.signForm(*ppf);

	std::cout << std::endl;
	
	std::cout << YELLOW << "[ shrubbery creation ]" << RESET << std::endl;
	president.executeForm(*scf);

	std::cout << std::endl << YELLOW << "[ robotomy request ]" << RESET << std::endl;
	president.executeForm(*rrf);

	std::cout << std::endl << YELLOW << "[ presidential pardon ]" << RESET << std::endl;
	president.executeForm(*ppf);

	std::cout << std::endl << YELLOW << "[ random form ]" << RESET << std::endl;
	Form *rand;
	rand = someRandomIntern.makeForm("random form", "Bender");
	if (rand) {
		president.signForm(*rand);
		president.executeForm(*rand);
		delete rand;
	}

	delete scf;
	delete rrf;
	delete ppf;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:56:45 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 13:26:36 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void):
Form("ShrubberyCreationForm", 145, 137), target(""){ }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
Form("ShrubberyCreationForm", 145, 137), target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
Form("ShrubberyCreationForm", 145, 137), target(copy.getTarget()) { }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	this->target = copy.getTarget();
	return (*this);
}

const std::string &ShrubberyCreationForm::getTarget(void) const {
	return (this->target);
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (check_exec(executor)) {
		std::string		outName = (getTarget() + "_shrubbery");
		std::ofstream	outfile(outName.c_str());
		outfile << "               ,@@@@@@@," << std::endl;
		outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		outfile << "       |o|        | |         | |" << std::endl;
		outfile << "       |.|        | |         | |" << std::endl;
		outfile << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		std::cout << "ASCII trees have been drawn in " << target << "_shrubbery" << std::endl;
		outfile.close();
		return (true);
	}
	return (false);
}
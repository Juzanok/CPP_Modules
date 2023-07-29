/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:55:12 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 12:41:57 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			execGrade;

	void	check_grade();

public:

	Form(void);
	Form(const std::string &name, int signgrade, int execgrade);
	Form(const Form &copy);
	~Form(void);

	Form	&operator=(const Form &copy);

	bool	beSigned(const Bureaucrat &bueraucrat);

	const std::string&	getName(void) const;
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;
	bool				getIsSigned(void) const;

	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream & stream, const Form& form);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:41:45 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 13:20:26 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define RESET          "\033[0m"
# define GREY           "\033[0m\033[90m"
# define RED            "\033[0m\033[91m"
# define GREEN          "\033[0m\033[92m"
# define YELLOW         "\033[0m\033[93m"
# define BLUE           "\033[0m\033[94m"
# define MAGENTA        "\033[0m\033[95m"
# define CYAN           "\033[0m\033[96m"
# define WHITE          "\033[0m\033[97m"

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
private:

	const std::string	name;
	int					grade;

	void check_grade(void);

public:

	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat(void);

	Bureaucrat	&operator=(const Bureaucrat &copy);

	void	incrementGrade(int amount);
	void	decrementGrade(int amount);

	void	signForm(Form &form);
	void	executeForm(Form const & form) const;

	const std::string&	getName(void) const;
	int					getGrade(void) const;

	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
};

std::ostream& operator<<(std::ostream & stream, const Bureaucrat& bureaucrat);

#endif
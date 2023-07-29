/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:41:45 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 01:56:06 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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

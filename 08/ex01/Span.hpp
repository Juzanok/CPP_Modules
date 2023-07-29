/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:19:09 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/18 10:54:53 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <vector>
# include <algorithm>

# define RESET	"\033[0m"
# define YELLOW	"\033[0m\033[93m"
# define CYAN	"\033[0m\033[96m"

class Span {
private:
	unsigned int		_size;
	std::vector<int>	_numbers;

public:
	Span(void);
	Span(unsigned int N);
	Span(Span const &copy);
	~Span(void);

	Span & operator=(const Span &copy);

	void	addNumber(int n);
	void	addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);

	long	shortestSpan() const;
	long	longestSpan() const;

	class FullSpanException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NotEnoughNumbersStoredException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
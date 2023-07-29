/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:18:02 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/28 15:01:01 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void	genRandomSpan(Span &sp, int size) {
	std::vector<int>	*vect;

	vect = new std::vector<int>(size);
	try {
		std::generate(vect->begin(), vect->end(), rand);
		sp.addNumbers(vect->begin(), vect->end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete vect;
}

int main(void) {
	srand(time(NULL));
	std::cout << std::endl << YELLOW << "[ Test given in the subject ]" << RESET << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span  : " << sp.longestSpan() << std::endl;



	std::cout << std::endl << YELLOW << "[ Generating a span filled with 10 000 numbers ]" << RESET << std::endl;
	Span sp2(10000);
	genRandomSpan(sp2, 10000);

	std::cout << "Shortest span : " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span  : " << sp2.longestSpan() << std::endl;



	std::cout << std::endl << YELLOW << "[ Exception test ]" << RESET << std::endl;
	std::cout << CYAN << "Trying to find the span with not enough numbers" << RESET << std::endl;
	try {
		Span esp1(3);
		std::cout << esp1.shortestSpan() << std::endl;
		std::cout << esp1.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << CYAN << "Trying to add numbers to a full span" << RESET << std::endl;
	try {
		Span esp2(3);
		genRandomSpan(esp2, 3);
		esp2.addNumber(654);
		esp2.addNumber(624);
		std::cout << esp2.shortestSpan() << std::endl;
		std::cout << esp2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
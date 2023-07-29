/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:55:34 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/21 10:42:39 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void) {
	int randNB = (rand() % 3) + 1;

	if (randNB == 1) {
		std::cout << "Type A generated" << std::endl;
		return (dynamic_cast<Base *>(new A));
	}
	else if (randNB == 2) {
		std::cout << "Type B generated" << std::endl;
		return (dynamic_cast<Base *>(new B));
	}
	else if (randNB == 3) {
		std::cout << "Type C generated" << std::endl;
		return (dynamic_cast<Base *>(new C));
	}
	return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) { }

	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) { }

	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) { }
}

int main(void) {
	Base * p1;
	Base * p2;
	Base * p3;

	srand(time(0));
	p1 = generate();
	p2 = generate();
	p3 = generate();

	std::cout << std::endl << YELLOW << "[ Pointer identify test ]" << RESET << std::endl;
	std::cout << "Type : ";
	identify(p1);
	std::cout << "Type : ";
	identify(p2);
	std::cout << "Type : ";
	identify(p3);

	std::cout << std::endl << YELLOW << "[ Reference identify test ]" << RESET << std::endl;
	std::cout << "Type : ";
	identify(*p1);
	std::cout << "Type : ";
	identify(*p2);
	std::cout << "Type : ";
	identify(*p3);

	delete p1;
	delete p2;
	delete p3;

	return (0);
}
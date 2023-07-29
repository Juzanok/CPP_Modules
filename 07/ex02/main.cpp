/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:35:06 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/24 01:55:27 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void ) {
	{
		std::cout << YELLOW << "[ Intiger array tests ]" << RESET << std::endl;
		Array <int> a(10);
		Array <int> b;

		for (int i = 0; i < a.size(); i++)
			a[i] = i;
		b = a;
		print_array("a", a);
		print_array("b", b);


		std::cout << std::endl << "Deep copy test" << std::endl;
		for (int i = b.size() - 1; i >= 0; i--)
			b[i] = b.size() - i - 1;
		print_array("a", a);
		print_array("b", b);
	}

	{
		std::cout << std::endl << YELLOW << "[ String array tests ]" << RESET << std::endl;
		Array <std::string> a(10);
		for (int i = 0; i < a.size(); i++)
			a[i] = "World";
		Array <std::string> b(a);
		print_array("a", a);
		print_array("b", b);
		

		std::cout << std::endl << "Deep copy test" << std::endl;
		for (int i = 0; i < a.size(); i++)
			a[i] = "Hello";
		print_array("a", a);
		print_array("b", b);
	}

	{
		std::cout << std::endl << YELLOW << "[ Boundary tests ]" << RESET << std::endl;
		Array <int> a(10);
		Array <int> b;
	
		for (int i = 0; i < a.size(); i++)
			a[i] = i;
	
		try {
			std::cout << "Trying to access a[9]  -> " << a[9] << std::endl;
			std::cout << "Trying to access a[10] -> " << a[10] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "Trying to access a[15] -> " << a[15] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "Trying to access a[-1] -> " << a[-1] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "Trying to access empty array b[0] -> " << b[0] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	return (0);
}
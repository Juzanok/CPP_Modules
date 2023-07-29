/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:23:08 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/24 01:19:57 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
	{std::cout << YELLOW << "[ Int test ]" << RESET << std::endl;
	int a = 2;
	int b = 3;

	std::cout << "Before swap : a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap  : a = " << a << ", b = " << b << std::endl;
	
	std::cout << "min( a, b ) = " << min(a,b) << std::endl;
	std::cout << "max( a, b ) = " << max(a,b) << std::endl;}



	{std::cout << std::endl << YELLOW << "[ Float test ]" << RESET << std::endl;
	float a = 42.5f;
	float b = 42.4f;

	std::cout << "Before swap : a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap  : a = " << a << ", b = " << b << std::endl;
	
	std::cout << "min( a, b ) = " << min(a,b) << std::endl;
	std::cout << "max( a, b ) = " << max(a,b) << std::endl;}



	{std::cout << std::endl << YELLOW << "[ Char test ]" << RESET << std::endl;
	char a = 'A';
	char b = 'Z';

	std::cout << "Before swap : a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap  : a = " << a << ", b = " << b << std::endl;
	
	std::cout << "min( a, b ) = " << min(a,b) << std::endl;
	std::cout << "max( a, b ) = " << max(a,b) << std::endl;}



	{std::cout << std::endl << YELLOW << "[ String test ]" << RESET << std::endl;
	std::string a = "chaine1";
	std::string b = "chaine2";

	std::cout << "Before swap : a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap  : a = " << a << ", b = " << b << std::endl;
	
	std::cout << "min( a, b ) = " << min(a,b) << std::endl;
	std::cout << "max( a, b ) = " << max(a,b) << std::endl;}



	{std::cout << std::endl << YELLOW << "[ Class test ]" << RESET << std::endl;
	Awesome a(2, "first");
	Awesome b(4, "second");

	std::cout << "Before swap : a = " << a.get_n() << ", b = " << b.get_n() << std::endl;
	swap(a, b);
	std::cout << "After swap  : a = " << a.get_n() << ", b = " << b.get_n() << std::endl;
	
	std::cout << "min( a, b ) = " << min(a,b).get_n() << std::endl;
	std::cout << "max( a, b ) = " << max(a,b).get_n() << std::endl << std::endl;
	

	Awesome x(4, "first");
	Awesome y(4, "second");
	std::cout << "min( x, y ) => " << min(x,y).get_type() << std::endl;
	std::cout << "max( x, y ) => " << max(x,y).get_type() << std::endl;}

	return (0);
}

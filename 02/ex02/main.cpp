/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:28:04 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/25 14:10:44 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );


	std::cout << "[ comparison operators ]" << std::endl;
	a = Fixed( 1234.4321f );
	if (a > c) std::cout << a << " > " << c << std::endl;
	a = Fixed( 16.16f );
	if (a < c) std::cout << a << " < " << c << std::endl;
	a = Fixed( 42.42f );
	if (a >= c) std::cout << a << " >= " << c << std::endl;
	if (a <= c) std::cout << a << " <= " << c << std::endl;
	if (a == c) std::cout << a << " == " << c << std::endl;
	if (a != b) std::cout << a << " != " << b << std::endl;
	std::cout << std::endl;


	std::cout << "[ arithmetic operators ]" << std::endl;
	a = Fixed( 16.16f );
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;
	std::cout << a << " + " << c << " = " << a + c << std::endl;
	std::cout << a << " - " << c << " = " << a - c << std::endl;
	std::cout << std::endl;


	Fixed x;
	Fixed const y( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "[ increment / decrement operators ]" << std::endl;
	std::cout << x << std::endl;
	std::cout << ++x << std::endl;
	std::cout << x << std::endl;
	std::cout << x++ << std::endl;
	std::cout << x << std::endl;
	std::cout << --x << std::endl;
	std::cout << std::endl;


	std::cout << "[ min / max functions ]" << std::endl;
	std::cout << "max " << Fixed::max( x, y ) << std::endl;
	std::cout << "min " << Fixed::min( x, y ) << std::endl;
	std::cout << std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:29:11 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/25 14:00:53 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	_fixedPointNumber = 0;
}

Fixed::Fixed(const int nb) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNumber = nb << _numberFractionalBits;
}

Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointNumber = roundf(nb * (1 << _numberFractionalBits));
	// _fixedPointNumber = float_number * 2^(fractional_bits) rounded up to the nearest whole number
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNumber = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const {
	return (_fixedPointNumber);
}

void Fixed::setRawBits( int const raw ) {
	_fixedPointNumber = raw;
}

int Fixed::toInt( void ) const {
	return (_fixedPointNumber >> _numberFractionalBits);
}

float Fixed::toFloat( void ) const {
	return ((float)_fixedPointNumber / (float)(1 << _numberFractionalBits));
}

std::ostream& operator<<(std::ostream &stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}
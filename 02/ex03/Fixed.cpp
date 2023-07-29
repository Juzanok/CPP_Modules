/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:29:11 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/25 14:12:04 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors -----------------------------------------------------------

Fixed::Fixed(void) {
	// std::cout << "Default constructor called" << std::endl;
	_fixedPointNumber = 0;
}

Fixed::Fixed(const int nb) {
	// std::cout << "Int constructor called" << std::endl;
	_fixedPointNumber = nb << _numberFractionalBits;
}

Fixed::Fixed(const float nb) {
	// std::cout << "Float constructor called" << std::endl;
	_fixedPointNumber = roundf(nb * (1 << _numberFractionalBits));
}

Fixed::Fixed(const Fixed &fixed) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

// Getters and Setters ----------------------------------------------------

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
	return (_fixedPointNumber / (float)(1 << _numberFractionalBits));
}

// Operators --------------------------------------------------------------

// Copy operator

Fixed &Fixed::operator=(const Fixed &fixed) {
	this->_fixedPointNumber = fixed.getRawBits();
	return (*this);
}

// Insertion operator

std::ostream& operator<<(std::ostream &stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}

// Comparison operators

bool Fixed::operator>(Fixed const &fixed) {
	return (_fixedPointNumber > fixed.getRawBits());
}

bool Fixed::operator<(Fixed const &fixed) {
	return (_fixedPointNumber < fixed.getRawBits());
}

bool Fixed::operator>=(Fixed const &fixed) {
	return (_fixedPointNumber >= fixed.getRawBits());
}

bool Fixed::operator<=(Fixed const &fixed) {
	return (_fixedPointNumber <= fixed.getRawBits());
}

bool Fixed::operator==(Fixed const &fixed) {
	return (_fixedPointNumber == fixed.getRawBits());
}

bool Fixed::operator!=(Fixed const &fixed) {
	return (_fixedPointNumber != fixed.getRawBits());
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed &fixed) {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) {
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

// Increment / Decrement operators

Fixed Fixed::operator++( int )
{
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed Fixed::operator--( int )
{
	Fixed temp = *this;
	--*this;
	return temp;
}

Fixed &Fixed::operator--( void )
{
	this->_fixedPointNumber--;
	return *this;
}

Fixed &Fixed::operator++( void )
{
	this->_fixedPointNumber++;
	return *this;
}

// Min / Max functions ----------------------------------------------------

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

Fixed const &Fixed::min(Fixed const &fixed1, Fixed const &fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

Fixed const &Fixed::max(Fixed const &fixed1, Fixed const &fixed2) {
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

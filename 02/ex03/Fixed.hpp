/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:20:48 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/12 12:44:18 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
private:

	int _fixedPointNumber;
	static const int _numberFractionalBits = 8;

public:

	Fixed(void);
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &fixed);
	~Fixed(void);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;

	Fixed & operator=(const Fixed &fixed);
	
	bool operator>(Fixed const &fixed);
	bool operator<(Fixed const &fixed);
	bool operator>=(Fixed const &fixed);
	bool operator<=(Fixed const &fixed);
	bool operator==(Fixed const &fixed);
	bool operator!=(Fixed const &fixed);

	Fixed operator+(const Fixed &fixed);
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed);
	Fixed operator/(const Fixed &fixed);

	Fixed operator++( int );
	Fixed &operator++( void );
	Fixed operator--( int );
	Fixed &operator--( void );

	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static Fixed const &min(Fixed const &fixed1, Fixed const &fixed2);
	static Fixed &max(Fixed &fixed1, Fixed &fixed2);
	static Fixed const &max(Fixed const &fixed1, Fixed const &fixed2);
};

std::ostream& operator<<(std::ostream &stream, const Fixed& fixed);

#endif
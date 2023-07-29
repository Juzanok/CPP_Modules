/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:20:48 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/30 16:55:28 by jkarosas         ###   ########.fr       */
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
	
	Fixed & operator = (const Fixed &fixed);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	int toInt( void ) const;
	float toFloat( void ) const;
};

std::ostream& operator<<(std::ostream &stream, const Fixed& fixed);

#endif
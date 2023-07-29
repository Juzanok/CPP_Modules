/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:49:21 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/11 07:06:17 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
private:

	int _fixedPointNumber;
	static const int _numberFractionalBits = 8;

public:

	Fixed(void);
	Fixed(const Fixed &copy);
	~Fixed(void);
	Fixed & operator = (const Fixed &fixed);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
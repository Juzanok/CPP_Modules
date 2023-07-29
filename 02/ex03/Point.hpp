/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:13:35 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/12 12:13:37 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
#include "Fixed.hpp"

class Point{
private:

	Fixed const x;
	Fixed const y;

public:

	Point(void);
	Point(const float X, const float Y);
	Point(const Point &point);
	~Point(void);
	
	Point & operator=(const Point &point);
	bool operator==(Point const &point) const;

	Fixed const &get_x() const;
	Fixed const &get_y() const;
	
};

std::ostream& operator<<(std::ostream &stream, const Point& point);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:19:16 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/12 12:13:49 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(Fixed(0)), y(Fixed(0)) {}
Point::Point(const float X, const float Y): x(Fixed(X)), y(Fixed(Y)) {}
Point::~Point(void) {}

Point::Point(const Point &point) {
	*this = point;
}

Point & Point::operator=(const Point &point) {
	(Fixed) this->x = (Fixed)point.x;
	(Fixed) this->y = (Fixed)point.y;
	return (*this);
}

bool Point::operator==(Point const &point) const{
	return(x.toFloat() == point.get_x().toFloat() && y.toFloat() == point.get_y().toFloat());
}

Fixed const &Point::get_x() const {
	return (this->x);
}

Fixed const &Point::get_y() const {
	return (this->y);
}

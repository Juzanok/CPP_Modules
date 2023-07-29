/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:32:56 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/25 14:23:14 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float vector_length(Point const &a, Point const &b) {
	Fixed temp1, temp2;

	temp1 = (b.get_x() - a.get_x()) * (b.get_x() - a.get_x());
	temp2 = (b.get_y() - a.get_y()) * (b.get_y() - a.get_y());
	return (sqrt(temp1.toFloat() + temp2.toFloat()));
}

bool check_line(Point const &a, Point const &b, Point const &point) {
	float pa, pb, ab;

	pa = vector_length(point, a);
	pb = vector_length(point, b);
	ab = vector_length(a, b);
	if (pa + pb == ab)
		return (true);
	return (false);
}

bool check_edge(Point const &a, Point const &b, Point const &c, Point const &point) {
	if (point == a || point == b || point == c)
		return (true);
	if (check_line(a, b, point) || check_line(b, c, point) || check_line(c, a, point))
		return (true);
	return (false);
}

Fixed result(Point const &p1, Point const &p2, Point const &p3) {
	Fixed temp1, temp2;
	temp1 = (p1.get_x() - p3.get_x()) * (p2.get_y() - p3.get_y());
	temp2 = (p2.get_x() - p3.get_x()) * (p1.get_y() - p3.get_y());
	return (temp1 - temp2);
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {
	Fixed	t1, t2, t3;
	bool	r_pos, r_neg;

	if (check_edge(a, b, c, point))
		return (false);
	t1 = result(point, a, b);
	t2 = result(point, b, c);
	t3 = result(point, c, a);
	r_pos = (t1 > 0) || (t2 > 0) || (t3 > 0);
	r_neg = (t1 < 0) || (t2 < 0) || (t3 < 0);
	
	return !(r_pos && r_neg);
}

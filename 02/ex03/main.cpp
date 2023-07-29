/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:28:04 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/25 14:23:35 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp" 

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point);

int main( void ) {
	Point point = Point(1, 0);
	Point a = Point(2, -2);
	Point b = Point(2, 2);
	Point c = Point(-2, -2);

	if (bsp(a, b, c, point))
		std::cout << "\033[36m" << "The point is inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "The point is not inside the triangle" << "\033[0m" << std::endl;
	return 0;
}

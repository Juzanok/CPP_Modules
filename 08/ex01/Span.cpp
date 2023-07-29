/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:30:47 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/28 14:53:56 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _size(0) { }
Span::Span(unsigned int N): _size(N) { }
Span::~Span(void) { }

Span::Span(Span const &copy) {
	_size = copy._size;
	_numbers = copy._numbers;
}

Span &Span::operator=(const Span &copy) {
	_size = copy._size;
	_numbers = copy._numbers;
	return (*this);
}

void	Span::addNumber(int n) {
	if (_numbers.size() >= _size)
		throw (FullSpanException());
	_numbers.push_back(n);
}

void	Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	if (_numbers.size() + std::distance(first, last) > _size)
		throw (FullSpanException());
	_numbers.insert(_numbers.end(), first, last);
}

long	Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersStoredException());
	std::vector<int> copy = _numbers;
	std::sort(copy.begin(), copy.end());

	std::vector<int>::iterator it1 = copy.begin() + 1;
	std::vector<int>::iterator it2 = copy.begin();
	long _shortestSpan = *it1 - *it2;

	for (it2 = copy.begin(); it2 < copy.end() - 1; it2++) {
		it1 = it2 + 1;
		if (*it1 - *it2 < _shortestSpan)
			_shortestSpan = *it1 - *it2;
	}
	return (_shortestSpan);
}

long	Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersStoredException());
	std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
	return (*max - *min);
}

const char* Span::FullSpanException::what() const throw() {
	return ("Exception : Span doesn't have enough space");
}

const char* Span::NotEnoughNumbersStoredException::what() const throw() {
	return ("Exception : There isn't enough numbers stored to find the longest and shortest spans");
}

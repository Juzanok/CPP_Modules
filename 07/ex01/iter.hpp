/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:23 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/24 01:24:22 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define RESET	"\033[0m"
# define YELLOW	"\033[0m\033[93m"

template <typename T> 
void	iter(T *address, int len, void (*f)(T&)) {
	for (int i = 0; i < len; i++) 
		(*f)(address[i]);
}

template <typename T> 
void	iter(const T *address, int len, void (*f)(const T&)) {
	for (int i = 0; i < len; i++) 
		(*f)(address[i]);
}


// Function templates for the tests
template <typename T>
void	add_one(T &input) {
	input++;
}

template <typename T>
void	subtract_one(T &input) {
	input--;
}

template <typename T>
void	ft_toupper(T &c) {
	c = std::toupper(c);
}

template <typename T>
void	print(const T& x) { std::cout << x << std::endl; return; }

template <typename T>
void	printEndl(T &c) {
	std::cout << c << " ";
}


// Class for the test
class Awesome {
public:
	Awesome(void) : _n(42) { return; }
	int get(void) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<(std::ostream& o, const Awesome& rhs) { o << rhs.get(); return o; }

#endif
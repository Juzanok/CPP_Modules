/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:19 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/24 01:20:44 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# define RESET	"\033[0m"
# define YELLOW	"\033[0m\033[93m"

template <typename T> 
void	swap(T &a, T &b) {
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T &a, T &b) {
	return (a < b ? a : b);
}

template <typename T>
T	max(T &a, T &b) {
	return (a > b ? a : b);
}


// Class for the test
class Awesome {
public:
	Awesome(void) : _n(0), _type(""){}
	Awesome(int n, std::string type): _n( n ), _type( type ) {}
	~Awesome(void) {}

	Awesome	&operator=(Awesome & a) {
		 _n = a._n;
		 _type = a._type;
		 return *this;
	}

	bool	operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool	operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	bool	operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	bool	operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	bool	operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	bool	operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }

	int	get_n() const { return _n; }
	const std::string &get_type() const { return _type; }

private:

	int _n;
	std::string _type;

};

#endif
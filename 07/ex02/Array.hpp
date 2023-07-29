/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:35:09 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/24 01:59:19 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <time.h>

# define MAX_VAL 750
# define RESET	"\033[0m"
# define YELLOW	"\033[0m\033[93m"

template <typename T> 
class Array {
private:
	int	_size;
	T	*_array;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &copy);
	~Array(void);

	Array	&operator=(const Array &copy);
	T		&operator[](int i);

	int size() const;

	class IndexOutOfBoundsException: public std::exception {
		virtual const char* what() const throw();
	};
};

template <typename T>
Array<T>::Array(void): _size(0), _array(new T[_size]) { }

template <typename T>
Array<T>::Array(unsigned int n): _size(n), _array(new T[_size]) { }

template <typename T>
Array<T>::Array(const Array<T> &copy) {
	_size = copy._size;
	_array = new T[_size];
	for (int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
}

template <typename T>
Array<T> & Array<T>::operator=(const Array<T> &copy) {
	_size = copy._size;
	if (_array != NULL)
		delete [](this->_array);
	_array = new T[_size];
	for (int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
	return (*this);
}

template <typename T>
Array<T>::~Array(void) {
	delete [](this->_array);
}

template <typename T>
T &Array<T>::operator[](int i) {
	if (i < 0 || i >= _size)
		throw (IndexOutOfBoundsException());
	return (_array[i]);
}
 
template <typename T>
int Array<T>::size() const {
	return (this->_size);
}

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw () {
	return ("IndexOutOfBoundsException: this index value is out of bounds");
}

// print array function for the tests 
template <typename T>
void	print_array(std::string title, Array <T> arr) {
	std::cout << title << " -> ";
	for(int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " "; 
	std::cout << std::endl;
}

#endif
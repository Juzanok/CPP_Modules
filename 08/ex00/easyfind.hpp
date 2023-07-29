/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:41:14 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/28 14:46:15 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

# define RESET	"\033[0m"
# define YELLOW	"\033[0m\033[93m"

class NoOccurrenceWasFoundException: public std::exception {
public:
	virtual const char* what() const throw() {
		return ("Exception : No occurence was found");
	};
};
	
template <typename T>
typename T::iterator easyfind(T &container, int i) {
	typename T::iterator result = std::find(container.begin(), container.end(), i);
	if (result == container.end())
		throw NoOccurrenceWasFoundException();
	return (result);
}

// Filling containers for the tests
template <typename T>
void fillContainer(T &container, int SIZE) {
	for (int i = 0; i < SIZE; i++)
		container.push_back(i);
}

#endif
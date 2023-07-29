/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:06:52 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/28 15:16:21 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iomanip>
# include <stack>
# include <list>
# include <algorithm>

# define RESET		"\033[0m"
# define YELLOW		"\033[0m\033[93m"
# define CYAN		"\033[0m\033[96m"
# define MAGENTA	"\033[0m\033[95m"

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack(void): std::stack<T>() {}
	MutantStack(MutantStack const &copy): std::stack<T>(copy) {*this = copy;}
	~MutantStack(void) {}

	MutantStack &operator=(const MutantStack &copy) {
		std::stack<T>::operator=(copy);
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
};

#endif
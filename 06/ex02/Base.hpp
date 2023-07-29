/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:51:17 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/14 11:49:04 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

# define YELLOW	"\033[0m\033[93m"
# define RESET	"\033[0m"

class Base{ 
public:
	virtual ~Base(void);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
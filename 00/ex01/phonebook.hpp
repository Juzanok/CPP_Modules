/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:00:15 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/10 15:14:29 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include "contact.hpp"

class PhoneBook{
private:
	Contact cont[8];
	static int current;
	static int count;
	std::string truncate(std::string str);
public:
	PhoneBook();
	void exec_add();
	void exec_search();
};

#endif
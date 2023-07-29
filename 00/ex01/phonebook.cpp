/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:30:24 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/10 15:32:11 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
int	PhoneBook::current = 0;
int	PhoneBook::count = 0;

PhoneBook::PhoneBook(){
	this->current = 0;
	this->count = 0;
}

void	PhoneBook::exec_add(){
	std::string first;
	std::string last;
	std::string nick;
	std::string phone;
	std::string secret;

	std::cout << "ADDING A NEW CONTACT" << std::endl;
	std::cout << std::setw(17) << std::left << "First name" << " : ";
	std::getline(std::cin, first);
	std::cout << std::setw(17) << std::left << "Last name" << " : ";
	std::getline(std::cin, last);
	std::cout << std::setw(17) << std::left << "Nickname" << " : ";
	std::getline(std::cin, nick);
	std::cout << std::setw(17) << std::left << "Phone number" << " : ";
	std::getline(std::cin, phone);
	std::cout << std::setw(17) << std::left << "Darkest secret" << " : ";
	std::getline(std::cin, secret);
	if(first.length() == 0 || last.length() == 0 || nick.length() == 0 || phone.length() == 0 || secret.length() == 0)
		std::cout << "Invalid contact. A contact cannot have empty fields" << std::endl;
	else
	{
		if (this->count < 8)
			this->count++;
		if (this->current == 8)
			this->current = 0;
		this->cont[this->current].set_first_name(first);
		this->cont[this->current].set_last_name(last);
		this->cont[this->current].set_nickname(nick);
		this->cont[this->current].set_phone_number(phone);
		this->cont[this->current].set_secret(secret);
		this->current++;
		std::cout << "Contact added" << std::endl;
	}
}

void	PhoneBook::exec_search(){
	int	nb = 0;
	std::string	str;

	if (this->count == 0)
	{
		std::cout << "The phonebook is empty, add some contacts" << std::endl;
		return;
	}
	for (int i = 0; i < this->count; i++)
	{
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		str = this->cont[i].get_info("first_name");
		std::cout << std::setw(10) << std::right << truncate(str) << "|";
		str = this->cont[i].get_info("last_name");
		std::cout << std::setw(10) << std::right << truncate(str) << "|";
		str = this->cont[i].get_info("nickname");
		std::cout << std::setw(10) << std::right << truncate(str) << std::endl;
	}
	while ((std::cout << "Choose the number of the contact : " && !(std::cin >> nb)) || (nb < 1 || nb > this->count))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input; Please choose a number between 1 and " << this->count << std::endl;
	}
	this->cont[nb - 1].display_info();
}

std::string PhoneBook::truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

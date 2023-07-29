/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:14:05 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/10 15:14:19 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	Contact::set_first_name(std::string str){
	f_name = str;
}

void	Contact::set_last_name(std::string str){
	l_name = str;
}

void	Contact::set_nickname(std::string str){
	n_name = str;
}

void	Contact::set_phone_number(std::string str){
	phone_number = str;
}

void	Contact::set_secret(std::string str){
	secret = str;
}

std::string	Contact::get_info(std::string type){
	if (type == "first_name")
		return f_name;
	else if (type == "last_name")
		return l_name;
	else if (type == "nickname")
		return n_name;
	else if (type == "phone_number")
		return phone_number;
	else if (type == "secret")
		return secret;
	return 0;
}

void	Contact::display_info(){
	std::cout << std::setw(15) << std::left << "First name" << " : " << this->f_name << std::endl;
	std::cout << std::setw(15) << std::left << "Last name" << " : " << this->l_name << std::endl;
	std::cout << std::setw(15) << std::left << "Nickname" << " : " << this->n_name << std::endl;
	std::cout << std::setw(15) << std::left << "Phone number" << " : " << this->phone_number << std::endl;
	std::cout << std::setw(15) << std::left << "Darkest secret" << " : " << this->secret << std::endl;
}

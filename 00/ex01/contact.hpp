/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:12:14 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/10 15:14:20 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact{
private:
	std::string f_name; // first name
	std::string l_name; // last name
	std::string n_name; // nick name
	std::string phone_number;
	std::string secret;
public:
	void	set_first_name(std::string str);
	void	set_last_name(std::string str);
	void	set_nickname(std::string str);
	void	set_phone_number(std::string str);
	void	set_secret(std::string str);
	void	display_info();
	std::string	get_info(std::string str);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:47:48 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/10 13:41:36 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl ( void ) {}

Harl::~Harl ( void ) {}

void Harl::debug( void ){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void ){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << 
		"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void ){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << 
		"I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void ){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain( std::string level )
{
	int	i = 0;
	std::string ComplaintLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*Complaint[]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (ComplaintLevel[i] != level && i < 4)
		i++;
	switch (i) {
	case 0:
		{void (Harl::*ptr) (void) = Complaint[0];
		(this->*ptr)();}
	case 1:
		{void (Harl::*ptr) (void) = Complaint[1];
		(this->*ptr)();}
	case 2:
		{void (Harl::*ptr) (void) = Complaint[2];
		(this->*ptr)();}
	case 3:
		{void (Harl::*ptr) (void) = Complaint[3];
		(this->*ptr)();}
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
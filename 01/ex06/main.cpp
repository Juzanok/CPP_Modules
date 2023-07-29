/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:47:26 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/10 13:38:58 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "[ Usage : ./harlFilter {complaint_level} ]" << std::endl;
		std::cerr << "Levels : DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}
	Harl complain;
	complain.complain(argv[1]);
	return (0);
}
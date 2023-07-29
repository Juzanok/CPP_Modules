/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:48:48 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/10 14:51:16 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for(int y = 0; y < (int)str.length(); y++)
				str[y] = toupper(str[y]);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}

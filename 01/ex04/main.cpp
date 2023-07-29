/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:17:03 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/20 17:36:38 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int error(std::string ermsg)
{
	std::cerr << "Error : " << ermsg << std::endl;
	std::cout << "Usage : ./replace <filename> <string1> <string2>" << std::endl;
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (error("Wrong number of arguments"));
	if (argv[1] == "")
		return (error("Invalid file name"));
	if (argv[2] == "" || argv[3] == "")
		return (error("Strings <string1> and <string2> can't be empty"));

	Replace sed(argv[1], argv[2], argv[3]);
	sed.replace_string();
	return (0);
}

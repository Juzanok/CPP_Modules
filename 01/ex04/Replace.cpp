/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:43:37 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/10 13:21:16 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string string1, std::string string2) {
	this->filename = filename;
	this->string1 = string1;
	this->string2 = string2;
}

Replace::~Replace( void ) {}

std::string Replace::read_file( void ) {
	std::string result, temp;
	std::ifstream infile(filename);

	if (infile.is_open())
	{
		while (!infile.eof())
		{
			std::getline(infile, temp);
			result += temp + "\n";
		}
	}
	infile.close();
	return (result);
}

void Replace::replace_string( void ) {
	std::string result = read_file();
	std::ofstream outfile(filename + ".replace");

	for (int i = 0; i < result.length(); i++)
	{
		if (result.compare(i, string1.length(), string1) == 0)
		{
			result.erase(i, string1.length());
			result.insert(i, string2);
		}
	}
	outfile << result;
	outfile.close();
}
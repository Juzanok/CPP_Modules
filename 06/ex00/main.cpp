/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:25:50 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/08 20:05:00 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main (int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "ERROR : not accepted argument number" << RESET << std::endl;
		std::cerr <<  "USAGE : ./converter <argument>" << std::endl;
		return (1);
	}
	Converter con(argv[1]);
	con.run_code();
	return (0);
}
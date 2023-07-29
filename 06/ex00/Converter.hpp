/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:21:59 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/14 17:17:41 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cmath>
# include <limits>

# define RESET          "\033[0m"
# define GREY           "\033[0m\033[90m"
# define RED            "\033[0m\033[91m"
# define GREEN          "\033[0m\033[92m"
# define YELLOW         "\033[0m\033[93m"
# define BLUE           "\033[0m\033[94m"
# define MAGENTA        "\033[0m\033[95m"
# define CYAN           "\033[0m\033[96m"
# define WHITE          "\033[0m\033[97m"

class Converter {
private:

	std::string input;

	int	inputType;
	static const int unknownType = -1;
	static const int charType = 0;
	static const int intType = 1;
	static const int floatType = 2;
	static const int doubleType = 3;

	char	charValue;
	int		intValue;
	float	floatValue;
	double	doubleValue;

	// Finding and seting input value
	bool	findInputType(void);
	int		checkSpecialCases(void);
	int		checkNumberCases(void);
	void	setInputTypeValue(void);
	
	// Converting and printing values
	void	print_Char(void);
	void	print_Int(void);
	void	print_Float(void);
	void	print_Double(void);

	// Checks if the convertion is possible
	bool	checkForChar(double number);
	bool	checkForInt(double number);
	bool	checkForFloat(double number);

	// Checks if we need ".0" at the end of a number
	const std::string	checkForDecimal(double number);

public:

	Converter(void);
	Converter(const std::string &input);
	Converter(const Converter &copy);
	~Converter(void);

	Converter	&operator=(const Converter &copy);

	void	run_code(void);
	
};

#endif
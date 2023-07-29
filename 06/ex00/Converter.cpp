/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:23:50 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/16 04:00:33 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void): input("") { }
Converter::Converter(const std::string &input): input(input) { }
Converter::~Converter(void) { }

Converter::Converter(const Converter &copy) {
	*this = copy;
}

Converter	&Converter::operator=(const Converter &copy) {
	this->input = copy.input;
	return (*this);
}

void	Converter::run_code(void) {
	if (!input[0]) {
		std::cerr << "Error : empty input" << std::endl;
		return ;
	}
	else if (!findInputType()) {
		std::cerr << "Error : unable to find input type" << std::endl;
		return ;
	}
	setInputTypeValue();
	print_Char();
	print_Int();
	print_Float();
	print_Double();
}

bool Converter::findInputType(void) {
	this->inputType = checkSpecialCases();
	if (this->inputType != this->unknownType)
		return (true);
	if (std::isdigit(input[0]) || input[0] == '-' || input[0] == '+' || input[0] == '.') {
		this->inputType = checkNumberCases();
		if (this->inputType != this->unknownType)
			return (true);
	}
	if (!input[1]) {
		this->inputType = this->charType;
		return (true);
	}
	return (false);
}

int Converter::checkSpecialCases(void) {
	const std::string specialFloat[] = { "inff", "+inff", "-inff", "nanf" };
	const std::string specialDouble[] = { "inf", "+inf", "-inf", "nan" };

	for (int i = 0; i < 4; i++) {
		if (this->input == specialFloat[i])
			return (this->floatType);
		else if (this->input == specialDouble[i])
			return (this->doubleType);
	}
	return (this->unknownType);
}

int Converter::checkNumberCases(void) {
	int	i = 0, decimalCount = 0;
	
	if ((input[i] == '-' || input[i] == '+') && input[1])
		i++;
	if (input[i] == '.' && (input[i + 1] == 'f' || !input[i + 1]))
		return (this->unknownType);
	while (std::isdigit(input[i]) || input[i] == '.') {
		if (input[i] == '.')
			decimalCount++;
		if (decimalCount > 1)
			return (this->unknownType);
		i++;
	}
	if (!input[i]) {
		if (decimalCount == 1)
			return (this->doubleType);
		return (this->intType);
	}
	else if (input[i] == 'f' && !input[i + 1] && decimalCount == 1)
		return (this->floatType);
	return (this->unknownType);
}

void	Converter::setInputTypeValue(void) {
	if (inputType == charType)
		charValue = input[0];
	else if (inputType == intType)
		intValue = atoi(input.c_str());
	else if (inputType == floatType)
		floatValue = atof(input.c_str());
	else if (inputType == doubleType)
		doubleValue = atof(input.c_str());
}

void	Converter::print_Char(void) {
	if (inputType == intType) {
		if (checkForChar(intValue))
			std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
	}
	else if (inputType == floatType) {
		if (checkForChar(floatValue))
			std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
	}
	else if (inputType == doubleType) {
		if (checkForChar(doubleValue))
			std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
	}
	else
		std::cout << "char: '" << charValue << "'" << std::endl;
}

bool	Converter::checkForChar(double number) {
	if (std::isnan(number) || number > 127 || number < 0)
		std::cout << "char: impossible" << std::endl;
	else if (number <= 31 || number == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		return true;
	return false;
}

void	Converter::print_Int(void) {
	if (inputType == charType)
			std::cout << "int: " << static_cast<int>(charValue) << std::endl;
	else if (inputType == intType)
		std::cout << "int: " << intValue << std::endl;
	else if (inputType == floatType) {
		if (checkForInt(floatValue))
			std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
	}
	else if (inputType == doubleType) {
		if (checkForInt(doubleValue))
			std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
	}
}

bool	Converter::checkForInt(double number) {
	if (number > std::numeric_limits<int>::max() ||
		number < std::numeric_limits<int>::min() ||
		number == std::numeric_limits<double>::infinity() ||
		number == -std::numeric_limits<double>::infinity() ||
		std::isnan(number)) 
	{
		std::cout << "int: impossible" << std::endl;
		return (false);
	}
	return (true);
}

void	Converter::print_Float(void) {
	if (inputType == charType)
		std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
	else if (inputType == intType)
		std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
	else if (inputType == floatType)
		std::cout << "float: " << floatValue << checkForDecimal(floatValue) << "f" << std::endl;
	else if (inputType == doubleType) {
		if (checkForFloat(doubleValue))
			std::cout << "float: " << static_cast<float>(doubleValue) << checkForDecimal(static_cast<float>(doubleValue)) << "f" << std::endl;
	}
}

bool	Converter::checkForFloat(double number) {
	if (number == std::numeric_limits<double>::infinity() || number == -std::numeric_limits<double>::infinity() || std::isnan(number))
		return (true);
	else if (number > std::numeric_limits<float>::max() || number < std::numeric_limits<float>::min()) {
		std::cout << "float: impossible" << std::endl;
		return (false);
	}
	return (true);
}

void	Converter::print_Double(void) {
	if (inputType == charType)
		std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
	else if (inputType == intType)
		std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
	else if (inputType == floatType) 
		std::cout << "double: " << static_cast<double>(floatValue) << checkForDecimal(static_cast<double>(floatValue)) << std::endl;
	else if (inputType == doubleType)
		std::cout << "double: " << static_cast<double>(doubleValue) << checkForDecimal(static_cast<double>(doubleValue)) << std::endl;
}

const std::string	Converter::checkForDecimal(double number) {
	if (number - static_cast<int>(number) == 0.0)
		return (".0");
	return ("");
}


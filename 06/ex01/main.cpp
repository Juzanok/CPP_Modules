/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:26:58 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/21 10:58:02 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdint.h>

struct Data {
	std::string str1;
	std::string str2;
	int year;
};

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

int	main(void) {
	Data obj;

	obj.str1 = "Hello";
	obj.str2 = " World!";
	obj.year = 2022;

	uintptr_t	serialized = serialize(&obj);
	std::cout << "Serialized value : " << serialized << std::endl << std::endl;

	Data		*deserialized = deserialize(serialized);
	std::cout << std::setw(20) << std::left << "Original object" << " : " << obj.str1 << obj.str2 << " " << obj.year << std::endl;
	std::cout << std::setw(20) << std::left << "Deserialized pointer" << " : " << deserialized->str1 << deserialized->str2 << " " << deserialized->year << std::endl;

	return (0);
}
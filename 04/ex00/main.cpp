/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:32:01 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 15:28:08 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

# define YELLOW	"\033[0m\033[93m"
# define RESET	"\033[0m"

int main()
{
	std::cout << YELLOW << "[ Test 1 : tests given in the subject ]" << RESET << std::endl;

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	
	std::cout << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;
	
	delete cat;
	delete dog;
	delete meta;

	std::cout << std::endl << YELLOW << "[ Test 2 : wrong animal tests ]" << RESET << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	std::cout << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;
	delete wrongCat;
	delete wrongMeta;

	return 0;
}
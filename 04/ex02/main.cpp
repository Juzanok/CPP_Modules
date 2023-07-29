/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:32:01 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 16:11:30 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

# define YELLOW	"\033[0m\033[93m"
# define RESET	"\033[0m"
# define NB_ANIMALS 6

int main()
{
	std::cout << YELLOW << "[ Test 1 : test given in the subject ]" << RESET << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	
	delete i;
	delete j;

	std::cout << std::endl << YELLOW << "[ Test 2 : array of animals test ]" << RESET << std::endl;

	Animal *animal[NB_ANIMALS];

	for (int i = 0; i < NB_ANIMALS; i++)
	{
		if (i < NB_ANIMALS / 2)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}

	std::cout << std::endl;
	for (int i = 0; i < NB_ANIMALS; i++) {
		animal[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = NB_ANIMALS - 1; i >= 0; i--) {
		delete animal[i];
	}

	std::cout << std::endl << YELLOW << "[ Test 3 : deep copy test ]" << RESET << std::endl;

	Dog dog1 = Dog();
	Dog dog2 = dog1;

	std::cout << std::endl;
	dog2.set_idea("I want a bone", 24);
	dog1.set_idea("I want some snacks", 24);

	dog1.print_idea(24);
	dog2.print_idea(24);

	std::cout << std::endl;
	Dog dog3 = dog1;
	std::cout << std::endl;
	
	dog1.print_idea(24);
	dog2.print_idea(24);
	dog3.print_idea(24);
	std::cout << std::endl;

	dog3.set_idea("Lets go for a walk", 24);
	dog1.print_idea(24);
	dog2.print_idea(24);
	dog3.print_idea(24);
	std::cout << std::endl;
	
	return 0;
}
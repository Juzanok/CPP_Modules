/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:06:46 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/28 15:09:48 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void test_empty(std::stack <int> &ostack, MutantStack<int> &mstack) {
	if (ostack.empty()) {
		std::cout << std::setw(25) << std::left << "The stack is empty";
		if (mstack.empty())
			std::cout << std::setw(25) << std::left << "The stack is empty" << std::endl;
	}
	else if (!ostack.empty()){
		std::cout << std::setw(25) << std::left << "The stack is not empty";
		if (!mstack.empty())
			std::cout << std::setw(25) << std::left << "The stack is not empty" << std::endl;
	}
}

int main( void ) {
	std::stack <int> ostack;
	MutantStack<int> mstack;

	std::cout << std::endl << YELLOW << "[ Stack member functions tests ]" << RESET << std::endl << std::endl;

	std::cout << CYAN << "[ Empty + Push test ]" << RESET << std::endl << std::endl;
	std::cout << MAGENTA << std::setw(25) << std::left << "Original stack:" << std::setw(25) << std::left << "Mutant stack:" << RESET << std::endl;
	test_empty(ostack, mstack);
	ostack.push(5);
	mstack.push(5);
	test_empty(ostack, mstack);


	std::cout << std::endl << CYAN << "[ Top + Size test ]" << RESET << std::endl << std::endl;
	std::cout << MAGENTA << std::setw(25) << std::left << "Original stack:" << std::setw(25) << std::left << "Mutant stack:" << RESET << std::endl;
	ostack.push(17);
	mstack.push(17);
	std::cout << "Top  : " << std::setw(18) << std::left << ostack.top() << "Top  : " << mstack.top() << std::endl;
	std::cout << "Size : " << std::setw(18) << std::left << ostack.size() << "Size : " << mstack.size() << std::endl;


	std::cout << std::endl << CYAN << "[ Pop test ]" << RESET << std::endl << std::endl;
	std::cout << MAGENTA << std::setw(25) << std::left << "Original stack:" << std::setw(25) << std::left << "Mutant stack:" << RESET << std::endl;
	ostack.pop();
	mstack.pop();
	std::cout << "Top  : " << std::setw(18) << std::left << ostack.top() << "Top  : " << mstack.top() << std::endl;
	std::cout << "Size : " << std::setw(18) << std::left << ostack.size() << "Size : " << mstack.size() << std::endl;



	std::cout << std::endl << YELLOW << "[ Mutant stack iterator + deep copy tests ]" << RESET << std::endl << std::endl;

	std::cout << MAGENTA << std::setw(25) << std::left << "Mutant stack:" << std::setw(25) << std::left << "Copy constructor:" << std::setw(25) << std::left << "Copy operator:" << RESET << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int> cc(mstack);
	MutantStack<int> co;

	co = mstack;

	mstack.push(1);
	cc.push(2);
	co.push(3);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	// Original mutant stack
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::setfill(' ') << std::setw(12) << std::right;

	// Copy constructor
	it = cc.begin();
	ite = cc.end();
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::setfill(' ') << std::setw(12) << std::right;

	// Copy operator 
	it = co.begin();
	ite = co.end();
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;



	std::cout << std::endl << YELLOW << "[ MutantStack / List comparison ]" << RESET << std::endl << std::endl;

	MutantStack	<int> stk;
	std::list	<int> lst;

	stk.push(21);	lst.push_back(21);
	stk.push(42);	lst.push_back(42);
	stk.push(84);	lst.push_back(84);
	stk.push(168);	lst.push_back(168);
	stk.push(336);	lst.push_back(336);
	stk.pop();		lst.pop_back();

	std::cout << MAGENTA << std::setw(25) << std::left << "Mutant stack:" << std::setw(25) << std::left << "List:" << RESET << std::endl;

	std::cout << "Top : " << std::setw(19) << std::left << stk.top() << "Back : " << lst.back() << std::endl;

	MutantStack<int>::iterator itS = stk.begin();
	MutantStack<int>::iterator iteS = stk.end();

	std::list<int>::iterator itL = lst.begin();
	std::list<int>::iterator iteL = lst.end();

	++itS;	++itL;
	--itS;	--itL;

	while (itS != iteS) {
		std::cout << *itS << " ";
		++itS;
	}
	std::cout << std::setfill(' ') << std::setw(14) << std::right;

	while (itL != iteL) {
		std::cout << *itL << " ";
		++itL;
	}
	std::cout << std::endl << std::endl;

	return (0);
}

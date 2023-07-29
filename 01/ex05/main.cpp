/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:47:26 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/10 13:26:15 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
	Harl a;

	a.complain("RandomTest");
	a.complain("DEBUG");
	a.complain("INFO");
	a.complain("WARNING");
	a.complain("ERROR");
}
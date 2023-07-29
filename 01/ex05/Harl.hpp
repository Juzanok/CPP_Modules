/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:43:30 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/28 09:38:09 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <fstream>
# include <string>

class Harl{
private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:

	Harl ( void );
	~Harl ( void );
	void complain( std::string level );

};

#endif
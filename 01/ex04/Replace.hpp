/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:43:40 by jkarosas          #+#    #+#             */
/*   Updated: 2022/09/20 17:27:28 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replace{
private:

	std::string string1;
	std::string string2;
	std::string filename;
	std::string read_file( void );

public:

	Replace(std::string filename, std::string string1, std::string string2);
	~Replace( void );
	void replace_string( void );

};

#endif
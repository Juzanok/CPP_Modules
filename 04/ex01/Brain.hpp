/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:36:03 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/01 15:40:16 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain{
private:
	std::string ideas[100];

public:
	Brain(void);
	Brain(const Brain &copy);
	~Brain(void);

	Brain & operator=(const Brain &copy);

	std::string *getIdeas();
	void setIdeas(std::string const &idea, int i);
};

#endif
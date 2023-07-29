/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:16:37 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 15:26:05 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
	AMateria *materia[4];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &copy);
	~MateriaSource(void);

	MateriaSource &operator=(const MateriaSource &copy);

	void learnMateria(AMateria* src);
	AMateria* createMateria(std::string const & type);
};

#endif
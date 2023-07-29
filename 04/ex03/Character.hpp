/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:07:17 by jkarosas          #+#    #+#             */
/*   Updated: 2022/10/31 16:23:26 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter{
private: 
	std::string name;
	AMateria *inventory[4];
	AMateria *unequip_storage[100];
	int	storage_idx;

public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &copy);
	~Character(void);

	Character &operator=(const Character &copy);

	std::string	const &getName() const;
	virtual void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif
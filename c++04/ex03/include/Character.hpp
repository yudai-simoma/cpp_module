/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:48:25 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 11:21:48 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Config.hpp"

class Character : public ICharacter {
	public:
		Character();
		Character(std::string const & name);
		Character(Character& other);
		Character& operator=(const Character& other);
		~Character();
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		std::string const & getName() const;
	private:
		std::string _name;
		AMateria* _materias[MAX_MATERIA];
};

#endif

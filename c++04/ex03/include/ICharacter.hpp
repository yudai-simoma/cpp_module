/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:40:47 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/04 01:41:32 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __I_CHARACTER_HPP
#define __I_CHARACTER_HPP

#include <string>

#include "AMateria.hpp"

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif

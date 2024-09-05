/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:22:13 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 11:29:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_MATERIA_HPP__
#define __A_MATERIA_HPP__

#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "Config.hpp"

// class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		std::string const & getType() const;
		void setType(const std::string type);
	protected:
	private:
		std::string _type;
};

#endif

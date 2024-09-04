/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:22:13 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/04 15:33:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_MATERIA_HPP__
#define __A_MATERIA_HPP__

#include <iostream>
#include <string>

#include "ICharacter.hpp"

#define RED_START "\033[1;31m"
#define COLOR_END "\033[0m"

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria& other);
		AMateria& operator=(const AMateria& other);
		~AMateria();

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		std::string const & getType() const;
		void setType(const std::string type);
	protected:
	private:
		std::string _type;
};

#endif

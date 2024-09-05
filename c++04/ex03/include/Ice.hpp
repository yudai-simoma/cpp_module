/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:22:22 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 10:26:40 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
#define __ICE_HPP__

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "Config.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();

		virtual AMateria* clone() const;
		void use(ICharacter& target);
	protected:
	private:
	    static const std::string ICE_TYPE;
};

#endif

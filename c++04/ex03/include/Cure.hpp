/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:35:12 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/04 15:48:28 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
#define __CURE_HPP__

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		virtual AMateria* clone() const;
		void use(ICharacter& target);
	protected:
	private:
	    static const std::string CURE_TYPE;
};



#endif

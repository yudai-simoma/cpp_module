/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:39:28 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/04 01:57:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __I_MATERIA_SOURCE_HPP__
#define __I_MATERIA_SOURCE_HPP__

#include <string>

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif

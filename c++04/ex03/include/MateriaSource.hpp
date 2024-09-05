/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:41:51 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 11:03:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIA_HPP__
#define __MATERIA_HPP__

#include <string>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Config.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
	protected:
	private:
		AMateria* _materias[MAX_MATERIA];
};

#endif

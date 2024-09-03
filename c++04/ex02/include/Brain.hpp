/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 02:31:59 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 03:15:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP
#define __BRAIN_HPP

#include <iostream>
#include <string>

#define RED_START "\033[1;31m"
#define COLOR_END "\033[0m"
#define MAX_IDEAS 100

class Brain {
	public:
		Brain();
		Brain(Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

        std::string getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
	protected:
	private:
		std::string _ideas[MAX_IDEAS];
};

#endif

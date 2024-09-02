/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 01:16:00 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 01:16:02 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_ANIMAL_HPP_
#define __WRONG_ANIMAL_HPP_

#include <iostream>
#include <string>

// 赤色の開始
#define RED_START "\033[1;31m"
// 色のリセット
#define COLOR_END "\033[0m"

class WrongAnimal {
   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    void makeSound() const;

    const std::string& getType() const;
    void setType(const std::string& type);

   protected:
    std::string _type;
};

#endif

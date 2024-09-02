/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 00:06:24 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 01:11:09 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP_
#define __ANIMAL_HPP_

#include <iostream>
#include <string>

// 赤色の開始
#define RED_START "\033[1;31m"
// 色のリセット
#define COLOR_END "\033[0m"

class Animal {
   public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    virtual void makeSound() const;

    const std::string& getType() const;
    void setType(const std::string& type);

   protected:
    std::string _type;
};

#endif

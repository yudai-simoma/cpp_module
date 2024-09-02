/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:42:17 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 00:38:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP_
#define __CAT_HPP_

#include <iostream>
#include <string>

#include "Animal.hpp"

class Cat : public Animal {
   public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;

   protected:
    static const std::string CAT_TYPE;

   private:
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 01:15:54 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 01:36:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_CAT_HPP_
#define __WRONG_CAT_HPP_

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();

    void makeSound() const;

   protected:
    static const std::string WRONG_CAT_TYPE;

   private:
};

#endif

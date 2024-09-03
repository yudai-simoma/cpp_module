/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:42:17 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 18:29:13 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP_
#define __CAT_HPP_

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;

      std::string getIdea(int index) const;
      void setIdea(int index, const std::string& idea);
   protected:
    static const std::string CAT_TYPE;

   private:
      Brain *brain;
};

#endif

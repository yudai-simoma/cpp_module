/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:43:05 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/08 21:09:38 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP_
#define __BASE_HPP_

#include <iostream>
#include <string>

class Base {
   public:
    virtual ~Base();

   protected:
   private:
};

void initialize();

Base * generate(void);

void identify(Base* p);

void identify(Base& p);

#endif

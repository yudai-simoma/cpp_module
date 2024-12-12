/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:43:05 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/13 00:17:34 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP_
#define __BASE_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>

class Base {
   public:
    virtual ~Base();

   protected:
   private:
};

void initialize();

Base* generate(void);

void identify(Base* p);

void identify(Base& p);

#endif

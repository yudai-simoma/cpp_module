/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:26:01 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/08 20:44:01 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <cstdlib>
#include <iostream>
#include <string>

struct Data {
    int value;
};

class Serializer {
   public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

   protected:
   private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
};

#endif

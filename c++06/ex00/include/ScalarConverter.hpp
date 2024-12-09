/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:12:50 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/08 20:43:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALAR_CONVERTER_HPP__
#define __SCALAR_CONVERTER_HPP__

#include <cstdlib>

class ScalarConverter {
   public:
    static int convert(const char* str);

   protected:
   private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionUtils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:18:08 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/20 02:07:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONVERSION_UTILS_HPP__
#define __CONVERSION_UTILS_HPP__

#include <float.h>

#include <cctype>
#include <cfloat>
#include <climits>  // Add this line
#include <cstdlib>  // for strtod, strtol
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ConversionUtils {
   public:
    static char c;
    static int intNum;
    static double doubleNum;
    static float floatNum;

    static std::string determineType(const std::string &input);
    static bool isEmpty(const std::string &input);
    static bool isSingleChar(const std::string &input);
    static bool isInteger(const std::string &input, long &value);
    static bool isFloatingPoint(const std::string &input, bool &endsWithF);
    static bool isSpecialFloatingPoint(const std::string &input);
    static void toChar(const std::string input, const std::string &type);
    static void toInt(const std::string input, const std::string &type);
    static void toDouble(const std::string input, const std::string &type);
    static void toFloat(const std::string input, const std::string &type);

    static char getC();
    static void setC(char a);
    static int getIntNum();
    static void setIntNum(int num);
    static double getDoubleNum();
    static void setDoubleNum(double num);
    static float getFloatNum();
    static void setFloatNum(float num);
};

#endif

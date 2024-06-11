/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:17:32 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/12 00:59:26 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP_
#define __HARL_HPP_

#include <iostream>
#include <string>

class Harl {
   public:
    Harl();
    ~Harl();
    void complain(std::string level);

   private:
    Harl(const Harl& other);
    Harl& operator=(const Harl& other);
    void debug();
    void info();
    void warning();
    void error();

    static const int LEVEL_NUM = 4;
    static const std::string DEBUG;
    static const std::string INFO;
    static const std::string WARNING;
    static const std::string ERROR;

    typedef void (Harl::*FunctionPtr)();
    FunctionPtr _funcArray[LEVEL_NUM];
};

enum LEVEL { DEBUG_NUM = 0, INFO_NUM = 1, WARNING_NUM = 2, ERROR_NUM = 3 };

#endif

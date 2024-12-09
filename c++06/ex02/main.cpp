/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:26:21 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/08 21:28:09 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    initialize();
    Base* ptr = generate();
    std::cout << "Pointer identification: ";
    identify(ptr);

    std::cout << "Reference identification: ";
    identify(*ptr);

    delete ptr;
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:07:32 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/08 21:26:50 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    std::cout << "Base: Destructor" << std::endl;
}

void initialize() {
    // 乱数の初期化
    std::srand(std::time(NULL));
}

Base* generate(void) {
    int randValue = std::rand() % 3;

    if (randValue == 0) {
        std::cout << "Generated A" << std::endl;
        return new A();
    } else if (randValue == 1) {
        std::cout << "Generated B" << std::endl;
        return new B();
    } else if (randValue == 2) {
        std::cout << "Generated C" << std::endl;
        return new C();
    } else {
        return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "p is an A object" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "p is an B object" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "p is an C object" << std::endl;
    } else {
        std::cout << "Unknown Type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "p is an A object" << std::endl;
        return;
    } catch (std::bad_cast&) {
    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "p is an B object" << std::endl;
        return;
    } catch (std::bad_cast&) {
    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "p is an C object" << std::endl;
        return;
    } catch (std::bad_cast&) {
    }

    std::cout << "Unknown Type" << std::endl;
}

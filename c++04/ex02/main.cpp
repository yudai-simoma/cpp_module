/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 02:02:41 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 19:38:45 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Animal.hpp"
#include "./include/Cat.hpp"
#include "./include/Dog.hpp"

int main() {
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "j: " << j->getType() << " " << std::endl;
    std::cout << "i: " << i->getType() << " " << std::endl;
    j->makeSound();  // will output the cat sound!
    i->makeSound();
    // meta->makeSound();
    // delete meta;
    delete j;
    delete i;

    // コピーコンストラクタのテスト
    Cat originalCat;
    Cat copiedCat(originalCat);
    copiedCat.makeSound();
    std::cout << "Copied Cat type: " << copiedCat.getType() << std::endl;

    // コピー代入演算子のテスト
    Dog originalDog;
    Dog assignedDog;
    assignedDog = originalDog;
    assignedDog.makeSound();
    std::cout << "Assigned Dog type: " << assignedDog.getType() << std::endl;

    return 0;
}

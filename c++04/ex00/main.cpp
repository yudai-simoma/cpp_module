/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:47:09 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 19:38:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "j: " << j->getType() << " " << std::endl;
    std::cout << "i: " << i->getType() << " " << std::endl;
    j->makeSound();  // will output the cat sound!
    i->makeSound();
    meta->makeSound();
    delete meta;
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

    // Animal クラスの動作確認
    Animal baseAnimal;
    baseAnimal.setType("Some Animal");
    std::cout << "Base Animal type: " << baseAnimal.getType() << std::endl;

    const WrongAnimal* meta1 = new WrongAnimal();
    const WrongAnimal* i1 = new WrongCat();
    std::cout << "i1: " << i1->getType() << " " << std::endl;
    i1->makeSound();
    meta1->makeSound();
    delete meta1;
    delete i1;

    return 0;
}

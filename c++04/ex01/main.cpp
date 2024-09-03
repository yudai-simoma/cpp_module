/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 02:02:41 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 14:00:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const static int ANIMAL_SIZE = 6;
	Animal *animals[ANIMAL_SIZE];
	for (int k = 0; k < ANIMAL_SIZE; k++) {
		if (k < ANIMAL_SIZE / 2) {
			animals[k] = new Dog();
		} else {
			animals[k] = new Cat();
		}
	}
	for (int k = 0; k < ANIMAL_SIZE; k++) {
		delete(animals[k]);
	}

	// ディープコピーが正しく行われていることを確認
    Dog originalDog;
    originalDog.setIdea(0, "Original Idea");

    Dog copiedDog(originalDog);  // コピーコンストラクタを使ってコピー

    // コピーが深いコピーかどうかを確認
    originalDog.setIdea(0, "Modified Idea");

    std::cout << "Original Dog's Idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog's Idea: " << copiedDog.getIdea(0) << std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:00:42 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 17:40:01 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// meのディープコピーができるか確かめる
// メモリリークをなくす
int main() {
    // MateriaSource のテスト
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Character のテスト
    ICharacter* me = new Character("me");
    AMateria* tmp1;
    AMateria* tmp2;
    tmp1 = src->createMateria("ice");
    me->equip(tmp1);
    tmp2 = src->createMateria("cure");
    me->equip(tmp2);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);  // ice を使う
    me->use(1, *bob);  // cure を使う

    // unequip のテスト
    me->unequip(0);  // ice を解除
    me->unequip(1);  // cure を解除

    // Character のコピーコンストラクタのテスト
    Character* copyMe = new Character(*(dynamic_cast<Character*>(me)));
    copyMe->equip(new Ice());  // コピー先に ice を装備
    copyMe->use(0, *bob);  // ice を使う (コピーされたオブジェクト)

    // コピー代入演算子のテスト
    Character other("other");
    other = *(dynamic_cast<Character*>(me));  // コピー代入演算子をテスト
    other.equip(new Cure());                  // コピー先に cure を装備
    other.use(0, *bob);                       // cure を使う

    // Ice/Cure のクローンメソッドのテスト
    AMateria* iceClone = tmp2->clone();
    me->equip(iceClone);  // クローンされた cure を装備
    me->use(0, *bob);     // クローンされた cure を使う

    // メモリ解放のテスト
    delete tmp1;
    delete tmp2;
    delete bob;
    delete me;
    delete src;
    delete copyMe;

    return 0;
}

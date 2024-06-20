/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:28:09 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/20 21:15:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

// TODO: std::coutの処理を削除
int main(void) {
    try {
        // テストケース 1: 点が三角形の内部にある場合（true）
        Point a1(1, 1);
        Point b1(4, 1);
        Point c1(1, 4);
        Point p1(2, 2);
        bool result1 = bsp(a1, b1, c1, p1);
        std::cout << "Test Case 1: " << (result1 ? "TRUE" : "FALSE")
                  << std::endl;

        // テストケース 2: 点が三角形の外部にある場合（false）
        Point a2(1, 1);
        Point b2(4, 1);
        Point c2(1, 4);
        Point p2(5, 5);
        bool result2 = bsp(a2, b2, c2, p2);
        std::cout << "Test Case 2: " << (result2 ? "TRUE" : "FALSE")
                  << std::endl;

        // テストケース 3: 点が三角形の辺上にある場合（false）
        Point a3(1, 1);
        Point b3(4, 1);
        Point c3(1, 4);
        Point p3(2.5, 1);
        bool result3 = bsp(a3, b3, c3, p3);
        std::cout << "Test Case 3: " << (result3 ? "TRUE" : "FALSE")
                  << std::endl;

        // テストケース 4: 点が三角形の頂点にある場合（false）
        Point a4(1, 1);
        Point b4(4, 1);
        Point c4(1, 4);
        Point p4(1, 1);
        bool result4 = bsp(a4, b4, c4, p4);
        std::cout << "Test Case 4: " << (result4 ? "TRUE" : "FALSE")
                  << std::endl;

        // テストケース 5: 点が負の座標の三角形の内部にある場合（true）
        Point a5(-4, -4);
        Point b5(-1, -4);
        Point c5(-4, -1);
        Point p5(-3, -3);
        bool result5 = bsp(a5, b5, c5, p5);
        std::cout << "Test Case 5: " << (result5 ? "TRUE" : "FALSE")
                  << std::endl;

        // テストケース 6:  三角形が直線上にあり、点がその直線上にある場合
        // (false)
        Point a6(1, 1);
        Point b6(4, 4);
        Point c6(7, 7);
        Point p6(2, 2);
        bool result6 = bsp(a6, b6, c6, p6);
        std::cout << "Test Case 6: " << (result6 ? "TRUE" : "FALSE")
                  << std::endl;

        // テストケース 7: 三角形が直線上にあり、点がその直線上にない場合
        // (false)
        Point a7(1, 1);
        Point b7(4, 4);
        Point c7(7, 7);
        Point p7(2, 3);
        bool result7 = bsp(a7, b7, c7, p7);
        std::cout << "Test Case 7: " << (result7 ? "TRUE" : "FALSE")
                  << std::endl;

    } catch (const std::overflow_error& e) {
        std::cerr << "Error: Overflow occurred: " << e.what() << std::endl;
        return 1;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: Runtime error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error: An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}

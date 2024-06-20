/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:12:09 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/20 21:15:26 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed calculateArea(Point const p1, Point const p2, Point const p3);

/**
 * 点が三角形の内部にあるかを判定する関数
 * 
 * a, b, c: 三角形の頂点
 * point: 判定対象の点
 * 戻り値: 点が三角形の内部にある場合は True、そうでない場合は False を返します。
 *        また、点が頂点上または辺上にある場合は False を返します。
 */
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // 三角形 ABC の面積を計算
    Fixed areaABC = calculateArea(a, b, c);
    
    // 三角形 PAB, PBC, PCA の面積を計算
    Fixed areaPAB = calculateArea(point, a, b);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaPCA = calculateArea(point, c, a);

    if (areaABC == 0 || areaPAB == 0 || areaPBC == 0 || areaPCA == 0) {
      return false;
    }
    // PAB + PBC + PCA が ABC の面積に等しければ内部にある
    return areaABC == (areaPAB + areaPBC + areaPCA);
}

// 三角形の面積を計算する関数
Fixed calculateArea(Point const p1, Point const p2, Point const p3) {
  // p1 を基準としたベクトルを計算
  Fixed v1x = p2.getX() - p1.getX();
  Fixed v1y = p2.getY() - p1.getY();
  Fixed v2x = p3.getX() - p1.getX();
  Fixed v2y = p3.getY() - p1.getY();

  // 外積の大きさを計算（外積、ベクトルが作る平行四辺形の面積）
  // 公式: uv = (ux * ​vy) - (uy * ​vx​)
  Fixed crossProductMagnitude = v1x * v2y - v1y * v2x;
  if (crossProductMagnitude < Fixed(0)) {
    crossProductMagnitude = Fixed(-1) * crossProductMagnitude;
  }

  // 面積は外積の大きさの半分
  return Fixed(0.5f) * crossProductMagnitude; 
}

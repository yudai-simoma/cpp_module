/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:28:47 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/17 00:04:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point {
	public: 
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point& operator=(const Point &other);
		~Point();

		const Fixed& getX() const;
		const Fixed& getY() const;
	private:
		Fixed const _x;
		Fixed const _y;
};

#endif

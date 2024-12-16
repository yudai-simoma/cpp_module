/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:22:15 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/16 21:33:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <stdlib.h>

template <typename T, typename F>
void iter(T* array, size_t length, F func) {
    if (array != NULL) {
        for (size_t i = 0; i < length; ++i) {
            func(array[i]);
        }
    }
}

#endif

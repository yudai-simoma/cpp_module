/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:45:26 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/16 21:27:05 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <stdlib.h>

#include <stdexcept>

template <typename T>
class Array {
   public:
    Array() : _data(NULL), _size(0) {
    }
    Array(unsigned int n) : _size(n) {
        if (n > 0) {
            this->_data = new T[n]();
        } else {
            this->_data = NULL;
        }
    }
    Array(const Array& other) : _size(other._size) {
        if (this->_size > 0) {
            this->_data = new T[this->_size];
            for (size_t i = 0; i < this->_size; ++i) {
                this->_data[i] = other._data[i];
            }
        } else {
            this->_data = NULL;
        }
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            // delete[] this->_data;
            this->_size = other._size;
            if (this->_size > 0) {
                this->_data = new T[this->_size];
                for (size_t i = 0; i < this->_size; ++i) {
                    this->_data[i] = other._data[i];
                }
            } else {
                this->_data = NULL;
            }
        }
        return *this;
    }
    ~Array() {
        delete[] this->_data;
    }

    // 要素アクセス演算子: []
    T& operator[](size_t index) {
        if (index >= this->_size) {
            throw std::exception();
        }
        return this->_data[index];
    }

    // 要素数を返す関数
    size_t size() const {
        return this->_size;
    }

   private:
    T* _data;
    size_t _size;
};

#endif

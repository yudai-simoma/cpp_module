/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:26:21 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/08 20:25:59 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"
#include <cassert>

int main() {
    Data* originalPtr = new Data();
    originalPtr->value = 42;
    
    std::cout << "Original Pointer: " << originalPtr << std::endl;
    std::cout << "Original Value: " << originalPtr->value << std::endl;
    
    uintptr_t serializedValue = Serializer::serialize(originalPtr);
    std::cout << "Serialized Value (hex): 0x" 
              << std::hex << serializedValue << std::dec << std::endl;
    
    Data* reconstructedPtr = Serializer::deserialize(serializedValue);
    
    std::cout << "Reconstructed Pointer: " << reconstructedPtr << std::endl;
    std::cout << "Reconstructed Value: " << reconstructedPtr->value << std::endl;
    
    std::cout << "Pointers match: " 
              << (originalPtr == reconstructedPtr ? "Yes" : "No") << std::endl;
    
    assert(originalPtr->value == reconstructedPtr->value);
    
    delete originalPtr;
    return 0;
}

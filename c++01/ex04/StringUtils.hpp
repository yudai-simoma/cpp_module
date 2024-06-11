/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:42:19 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/11 13:11:23 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STRINGUTILS_HPP__
#define __STRINGUTILS_HPP__

#include <iostream>
#include <string>

namespace StringUtils {
std::string replaceContents(const std::string& line, const std::string& s1,
                            const std::string& s2);
std::string replaceAtPosition(const std::string& line, size_t pos, size_t len,
                              const std::string& str);
}  // namespace StringUtils

#endif

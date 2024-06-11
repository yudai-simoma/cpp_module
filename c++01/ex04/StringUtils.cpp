/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:44:35 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/11 15:32:32 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringUtils.hpp"

std::string StringUtils::replaceAtPosition(const std::string& contents, size_t pos, size_t len,
                                           const std::string& str) {
    std::string replaceContents;

    replaceContents = contents.substr(0, pos);
    replaceContents += str;
    replaceContents += contents.substr(pos + len, contents.length());
    return replaceContents;
}

std::string StringUtils::replaceContents(const std::string& contents, const std::string& s1,
                                         const std::string& s2) {
    std::string replaceContents = contents;
    size_t index = 0;
    size_t serch_num = 0;

    while (true) {
        index = replaceContents.find(s2, serch_num);
        if (index == std::string::npos) {
            break;
        }
        replaceContents = replaceAtPosition(replaceContents, index, s2.length(), s1);
        serch_num = index + s1.length();
    }
    return replaceContents;
}

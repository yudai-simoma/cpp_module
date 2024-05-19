/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 00:18:34 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/19 09:29:44 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>

static void put_string_upper(std::string src) {
    std::locale l = std::locale::classic();
    for (int i = 0; i < (int)src.size(); i++) {
        std::cout << std::toupper(src[i], l);
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        put_string_upper("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        put_string_upper((std::string)argv[i]);
    }
    std::cout << std::endl;
    return 0;
}

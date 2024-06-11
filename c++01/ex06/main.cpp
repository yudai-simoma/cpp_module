/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:17:37 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/11 23:14:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    try {
        Harl harl;

        if (argc > 2) {
            std::cout << "Invalid parameters." << std::endl;
            return 1;
        } else if (argc == 2) {
            harl.complain(static_cast<std::string>(argv[1]));
        } else {
            harl.complain("");
        }

        return 0;
    } catch (...) {
        return 1;
    }
}

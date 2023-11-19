/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:26:04 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/19 15:36:24 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    
    std::cout << "• The memory address of the string variable is: " << &string << std::endl;
    std::cout << "• The memory address held by stringPTR is: " << stringPTR << std::endl;
    std::cout << "• The memory address held by stringREF is: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "• The string variable is: " << string << std::endl;
    std::cout << "• The stringPTR is: " << stringPTR << std::endl;
    std::cout << "• The stringREF is: " << stringREF << std::endl;
    return (0);
}
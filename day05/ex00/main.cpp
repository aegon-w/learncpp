/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:29:05 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/12 11:44:20 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat b("Bob", 150);
        std::cout << b;
        b.incrementGrade();
        std::cout << b;
        b.decrementGrade();
        std::cout << b;
        b.decrementGrade();
        std::cout << b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:35:56 by xshel             #+#    #+#             */
/*   Updated: 2024/01/20 05:34:42 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector<int> v;
    std::list<int> l;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        l.push_back(i);
    }
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "List: ";
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try
    {
        std::cout << "Vector: " << *easyfind(v, 8) << std::endl;
        std::cout << "List: " << *easyfind(l, 5) << std::endl;
        std::cout << "Vector: " << *easyfind(v, 11) << std::endl;
        std::cout << "List: " << *easyfind(l, 2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Not found" << std::endl;
    }
    return (0);
}
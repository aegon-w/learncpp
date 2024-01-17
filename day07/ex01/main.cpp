/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:04:09 by xshel             #+#    #+#             */
/*   Updated: 2024/01/17 03:29:29 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T const &a)
{
    std::cout << a << std::endl;
}

int main()
{
    char array[5] = {'a', 'b', 'c', 'd', 'e'};
    // int array[5] = {1, 2, 3, 4, 5};
    iter(array, 5, print);
    return (0);
}
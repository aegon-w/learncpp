/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:42 by m-boukel          #+#    #+#             */
/*   Updated: 2024/01/14 11:35:52 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <cinttypes>

typedef unsigned long           uintptr_t;

int main()
{
    // srand(time(NULL));
    int i = 4;
    long m = reinterpret_cast<long&>(i);
    std::cout << m << std::endl;
    i = reinterpret_cast<int&>(m);
    std::cout << i << std::endl;

    // inn -> long -> int = segfault
    
    // Data *data = new Data;
    // data->s1 = "Hello";
    // data->n = 42;
    // uintptr_t ptr = serialize(new Data);
    // std::cout << ptr << std::endl; // 105759274697488
    // data = deserialize(ptr);
    // std::cout << data->s1 << std::endl;
    // std::cout << data->n << std::endl;
    // Data *data = deserialize(serialize(new Data));
    // std::cout << data->s1 << std::endl;
    // std::cout << data->n << std::endl;
    // delete data;
    return (0);
}
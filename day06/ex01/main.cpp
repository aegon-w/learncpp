/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:01:03 by kali              #+#    #+#             */
/*   Updated: 2024/01/15 03:17:47 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"


int main()
{
    // int i = 4;
    // long m = reinterpret_cast<long&>(i);
    // std::cout << m << std::endl;
    // i = reinterpret_cast<int&>(m);
    // std::cout << i << std::endl; //undef behaver
    
    Data *data = new Data;
    data->s1 = "Hello";
    data->n = 42;
    // std::cout << data->s1 << std::endl;
    // std::cout << data->n << std::endl;
    // std::cout << reinterpret_cast<unsigned long>(data) << std::endl;
    // uintptr_t ptr = serialize(data);
    // std::cout << ptr << std::endl;
    // data = deserialize(ptr);
    // std::cout << "data->s1 :" << data->s1 << std::endl;
    // std::cout << "data->n  :" << data->n << std::endl;
    data = deserialize(serialize(data));
    std::cout << data->s1 << std::endl;
    std::cout << data->n << std::endl;
    delete data;
    return (0);
}
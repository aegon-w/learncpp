/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:28:55 by m-boukel          #+#    #+#             */
/*   Updated: 2024/01/15 03:00:08 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP


#include <iostream>
#include <cinttypes>
#include<cstdlib>

struct Data
{
    std::string s1;
    int n;
};

uintptr_t serialize(Data* ptr);
Data *deserialize(uintptr_t data);


#endif
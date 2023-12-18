/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:28:55 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/18 15:31:05 by m-boukel         ###   ########.fr       */
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
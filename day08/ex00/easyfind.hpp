/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:56:24 by xshel             #+#    #+#             */
/*   Updated: 2023/12/25 10:46:53 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>
#include <algorithm>
#include <iostream>
#include <vector>


template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return (it);
}



#endif
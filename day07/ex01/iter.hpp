/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:02:21 by xshel             #+#    #+#             */
/*   Updated: 2024/01/18 11:58:00 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename U>

void iter(T *array, int length, U f)
{
    if (!array || !f)
        return;
    for (int i = 0; i < length; i++)
        f(array[i]);
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:48:19 by xshel             #+#    #+#             */
/*   Updated: 2023/12/20 10:50:36 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <exception>

template <typename T>

class Array
{
    private:
        T *_array;
        unsigned int _length;
    public ::
        Array();
        Array(unsigned int n);
        Array(Array const &src);
        ~Array();
        Array &operator=(Array const &src);
        T &operator[](unsigned int n);
        unsigned int size() const;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &src);


#endif
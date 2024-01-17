/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:48:19 by xshel             #+#    #+#             */
/*   Updated: 2024/01/17 03:35:41 by kali             ###   ########.fr       */
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
        T *array;
        unsigned int length;
    public :
        Array()
        {
            array = NULL;
            length = 0;
        }
        Array(unsigned int n)
        {
            array = new T[n];
            length = n;   
        };
        Array(Array const &src)
        {
            array = new T[src.size()];
            length = src.size();
            for (unsigned int i = 0; i < src.size(); i++)
                array[i] = src[i];
        };
        ~Array(){
            delete [] array;
        };

        Array& operator=( const Array& rhs ) {
            if ( this != &rhs ) {
            delete [] array;
            array = new T[rhs.size()];
            length = rhs.length;
            for ( unsigned int i( 0 ); i < length; i++ )
                array[i] = rhs.array[i];
            }
            return *this;
        }

        T& operator[]( unsigned int i ) const {
            if ( i >= length )
                throw OutOfBoundsException();
            return array[i];
        }
        
        unsigned int size() const
        {
            return (length);
        };

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Out of bounds";
                }
        };

};




#endif
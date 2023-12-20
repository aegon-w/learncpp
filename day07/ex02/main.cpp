/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:30:19 by xshel             #+#    #+#             */
/*   Updated: 2023/12/20 11:47:25 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
    for ( unsigned int i( 0 ); i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}

int main()
{
    Array<int> array(5);
    for (unsigned int i = 0; i < array.size(); i++)
        array[i] = i;
    std::cout << array << std::endl;
    Array<int> array2(array);
    std::cout << array2 << std::endl;
    try
    {
        std::cout << array[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
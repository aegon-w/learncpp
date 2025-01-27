/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:44:57 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/26 14:04:29 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

    float x = 2;
    float y = 5;
    std::cout << "a + b = " << x + y << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}
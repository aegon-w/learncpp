/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:31:55 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/19 13:33:10 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = n << fractional_bits;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = roundf(f * (1 << fractional_bits));
}

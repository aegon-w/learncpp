/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:16:40 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/19 13:57:34 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

Fixed &Fixed::operator=(Fixed const &f)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &f)
    {
        this->fixed_point = f.getRawBits();
    }
    return (*this);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point = raw;
}
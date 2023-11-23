/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:54:45 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/23 13:59:13 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : fixed_point(n << fractional_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f) : fixed_point(f * (1 << fractional_bits))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    this->fixed_point = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->fixed_point / (1 << fractional_bits));
}

int Fixed::toInt(void) const
{
    return (this->fixed_point >> fractional_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}

bool Fixed::operator>(Fixed const &f) const
{
    return (this->fixed_point > f.getRawBits());
}

bool Fixed::operator<(Fixed const &f) const
{
    return (this->fixed_point < f.getRawBits());
}

bool Fixed::operator>=(Fixed const &f) const
{
    return (this->fixed_point >= f.getRawBits());
}

bool Fixed::operator<=(Fixed const &f) const
{
    return (this->fixed_point <= f.getRawBits());
}

bool Fixed::operator==(Fixed const &f) const
{
    return (this->fixed_point == f.getRawBits());
}

bool Fixed::operator!=(Fixed const &f) const
{
    return (this->fixed_point != f.getRawBits());
}

Fixed Fixed::operator+(Fixed const &f) const
{
    return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed Fixed::operator-(Fixed const &f) const
{
    return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed Fixed::operator*(Fixed const &f) const
{
    return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed Fixed::operator/(Fixed const &f) const
{
    return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed &Fixed::operator++()
{
    this->fixed_point++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed &Fixed::operator--()
{
    this->fixed_point--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    return (f1 > f2 ? f1 : f2);
}

Fixed const &Fixed::min(Fixed const &f1, Fixed const &f2)
{
    return (f1 < f2 ? f1 : f2);
}

Fixed const &Fixed::max(Fixed const &f1, Fixed const &f2)
{
    return (f1 > f2 ? f1 : f2);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:45:28 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/24 12:46:53 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class   Fixed
{
    private :
        int                fixed_point;
        static const int   fractional_bits = 8; 
    public:
        Fixed();
        Fixed(int const n);
        Fixed(float const f);
        ~Fixed();
        Fixed(Fixed const &f);
        Fixed &operator=(Fixed const &f);
        float toFloat() const;
        int toInt() const;
        int getRawBits() const;
        void setRawBits(int const raw);

        bool operator>(Fixed const &f) const;
        bool operator<(Fixed const &f) const;
        bool operator>=(Fixed const &f) const;
        bool operator<=(Fixed const &f) const;
        bool operator==(Fixed const &f) const;
        bool operator!=(Fixed const &f) const;

        Fixed operator+(Fixed const &f) const;
        Fixed operator-(Fixed const &f) const;
        Fixed operator*(Fixed const &f) const;
        Fixed operator/(Fixed const &f) const;
        
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
        static Fixed &min(Fixed &f1, Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static Fixed const &min(Fixed const &f1, Fixed const &f2);
        static Fixed const &max(Fixed const &f1, Fixed const &f2);
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif
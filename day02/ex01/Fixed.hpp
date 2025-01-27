/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:31:37 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/23 13:56:14 by m-boukel         ###   ########.fr       */
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
};
std::ostream &operator<<(std::ostream &o, Fixed const &f);



#endif
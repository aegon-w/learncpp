/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:14:13 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/19 13:16:30 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>


class   Fixed
{
    private :
        int                fixed_point;
        static const int   fractional_bits = 8; 
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed const &f);
        Fixed &operator=(Fixed const &f);
        int getRawBits() const;
        void setRawBits(int const raw);
};



#endif
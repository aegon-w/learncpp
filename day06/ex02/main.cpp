/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:09:30 by m-boukel          #+#    #+#             */
/*   Updated: 2024/01/14 12:06:20 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.hpp"
// class L : public Base {};

int main()
{
    // Base *base = new L;
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:57:09 by xshel             #+#    #+#             */
/*   Updated: 2023/11/07 17:28:38 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>


int main()
{
    Zombie zombie("Foo");
    zombie.announce();
    Zombie *zombie2 = newZombie("Bar");
    zombie2->announce();
    return (0);
}
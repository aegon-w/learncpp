/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:57:09 by xshel             #+#    #+#             */
/*   Updated: 2023/11/20 16:06:27 by m-boukel         ###   ########.fr       */
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
    delete zombie2;
    randomChump("Baz");
    return (0);
}
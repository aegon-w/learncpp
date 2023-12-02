/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:24:21 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/01 14:56:09 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("ClapTrap");
    ClapTrap clap2(clap);
    ClapTrap clap3("ClapTrap3");
    clap3 = clap2;
    
    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(5);
    
    return (0);
}
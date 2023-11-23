/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:43:22 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/20 11:09:24 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


void Zombie::setName(std::string name)
{
    this->_name = name;
}
Zombie::Zombie()
{
    std::cout << "Zombie: " << this->_name << "was born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie: " << this->_name << " was died" << std::endl;
}


void Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
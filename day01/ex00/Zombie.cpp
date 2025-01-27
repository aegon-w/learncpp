/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:38:29 by xshel             #+#    #+#             */
/*   Updated: 2023/11/09 16:32:40 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie: " <<this->_name<< " was born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie:" << this->_name << " was died" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->_name << ": Braiiiiiiinnnssss..." << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:38:29 by xshel             #+#    #+#             */
/*   Updated: 2023/11/07 17:40:24 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie was born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie was died" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->_name << ": Braiiiiiiinnnssss..." << std::endl;
}
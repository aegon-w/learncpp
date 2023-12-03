/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:00:51 by xshel             #+#    #+#             */
/*   Updated: 2023/12/03 19:54:59 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = obj.type;
}

Animal &Animal::operator=(const Animal &obj)
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal makesound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

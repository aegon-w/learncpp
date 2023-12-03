/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:07:20 by xshel             #+#    #+#             */
/*   Updated: 2023/12/03 19:17:13 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = obj.type;
}

Dog &Dog::operator=(const Dog &obj)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog makesound" << std::endl;
}

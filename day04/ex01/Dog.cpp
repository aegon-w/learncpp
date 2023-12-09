/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:52:59 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/09 16:15:19 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog brain created" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
}

Dog &Dog::operator=(const Dog &obj)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
        delete this->brain;
        this->brain = new Brain(*obj.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

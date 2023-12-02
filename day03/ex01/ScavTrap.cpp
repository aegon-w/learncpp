/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:20:26 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/30 11:37:35 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = src;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap parameter constructor called" << std::endl;
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}
ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    std::cout << "ScavTrap assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
    }
    return (*this);
}

void ScavTrap::attack(const std::string & target)
{
    if (this->hit_points && this->energy_points)
    {
        this->hit_points -= attack_damage ;
        this->energy_points -= 1;
        std::cout << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout  << this->name << " is now in Gate keeper mode" << std::endl;
}

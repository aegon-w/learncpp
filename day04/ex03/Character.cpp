/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:44:12 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/07 11:48:04 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    this->name = "default";
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(Character const &src)
{
    *this = src;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete this->inventory[i];
}

Character &Character::operator=(Character const &rhs)
{
    if (this != &rhs)
    {
        this->name = rhs.name;
        for (int i = 0; i < 4; i++)
            delete this->inventory[i];
        for (int i = 0; i < 4; i++)
            this->inventory[i] = rhs.inventory[i]->clone();
    }
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
        this->inventory[idx]->use(target);
}

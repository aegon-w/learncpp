/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:33:02 by xshel             #+#    #+#             */
/*   Updated: 2023/12/03 19:33:37 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
}

Brain &Brain::operator=(const Brain &obj)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &obj)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = obj.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
    this->ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
    return (this->ideas[i]);
}


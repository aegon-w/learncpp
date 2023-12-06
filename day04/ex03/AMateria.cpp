/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:23:04 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/05 16:30:21 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
}
AMateria &AMateria::operator=(AMateria const &rhs)
{
    std::cout << "AMateria assignation operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.getType();
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "default ICharacter" << std::endl;
}

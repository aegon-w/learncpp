/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:25:45 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/09 10:53:44 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    *this = src;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->materia[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
            delete this->materia[i];
        for (int i = 0; i < 4; i++)
            this->materia[i] = rhs.materia[i]->clone();
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (this->materia[i] == NULL)
        {
            this->materia[i] = m;
            break;
        }
    }
    if (i == 4)
        delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (this->materia[i] != NULL && this->materia[i]->getType() == type)
            return (this->materia[i]->clone());
    }
    std::cout << "Materia not found" << std::endl;
    return (NULL);
}
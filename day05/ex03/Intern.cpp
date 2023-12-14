/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:15:39 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/14 19:32:14 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &src) { *this = src; }

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return (*this);
}

AForm*    Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    switch (name.compare(forms[0]))
    {
        case 0:
            std::cout << "Intern creates " << name << std::endl;
            return (new PresidentialPardonForm(target));
        case 1:
            std::cout << "Intern creates " << name << std::endl;
            return (new RobotmyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << name << std::endl;
            return (new ShrubberyCreationForm(target));
        default:
            std::cout << "Intern doesn't know this form" << std::endl;
            return (NULL);
    }
}

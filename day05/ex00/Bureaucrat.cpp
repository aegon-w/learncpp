/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:42:10 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/12 15:12:59 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.name)
{
    *this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
        this->grade = rhs.grade;
    return (*this);
}

std::string const   Bureaucrat::getName() const
{
    return (this->name);
}

int                 Bureaucrat::getGrade() const
{
    return (this->grade);
}

void                Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade--;
}

void                Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return (o);
}

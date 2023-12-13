/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:59:54 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/12 15:13:30 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
}

AForm::AForm(AForm const &src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    *this = src;
}

AForm &AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
        this->signedAForm = rhs.signedAForm;
    return (*this);
}

AForm::~AForm()
{
}

std::string const   AForm::getName() const
{
    return (this->name);
}

bool                AForm::getSignedAForm() const
{
    return (this->signedAForm);
}

int                 AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

int                 AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void                AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() >= this->gradeToSign)
        throw AForm::GradeTooLowException();
    else
        this->signedAForm = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
    o << rhs.getName() << ", AForm grade to sign " << rhs.getGradeToSign() << ", AForm grade to execute " << rhs.getGradeToExecute() << ", AForm signed " << rhs.getSignedAForm() << std::endl;
    return (o);
}

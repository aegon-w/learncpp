/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:59:54 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/12 15:13:20 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
}

Form::Form(Form const &src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    *this = src;
}

Form &Form::operator=(Form const &rhs)
{
    if (this != &rhs)
        this->signedForm = rhs.signedForm;
    return (*this);
}

Form::~Form()
{
}

std::string const   Form::getName() const
{
    return (this->name);
}

bool                Form::getSignedForm() const
{
    return (this->signedForm);
}

int                 Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int                 Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void                Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() >= this->gradeToSign)
        throw Form::GradeTooLowException();
    else
        this->signedForm = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
    o << rhs.getName() << ", form grade to sign " << rhs.getGradeToSign() << ", form grade to execute " << rhs.getGradeToExecute() << ", form signed " << rhs.getSignedForm() << std::endl;
    return (o);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:11:25 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/13 16:11:42 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), target(src.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
        this->target = rhs.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
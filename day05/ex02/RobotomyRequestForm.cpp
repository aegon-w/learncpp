/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:58:05 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/15 11:26:26 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm() {}

RobotmyRequestForm::RobotmyRequestForm(std::string target) : AForm("RobotmyRequestForm", 72, 45), target(target) {}

RobotmyRequestForm::RobotmyRequestForm(RobotmyRequestForm const &src) : AForm(src), target(src.target) {}

RobotmyRequestForm::~RobotmyRequestForm() {}

RobotmyRequestForm &RobotmyRequestForm::operator=(RobotmyRequestForm const &rhs)
{
    if (this != &rhs)
        this->target = rhs.target;
    return (*this);
}

void RobotmyRequestForm::execute(Bureaucrat const &executor) const
{
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else {
        srand(time(NULL));
        if ( rand() % 2 == 0 )
            std::cout << "BZZZZZT! " << this->target << " has been robotomized successfully 50% of the time" << std::endl;
        else
            std::cout << "Robotomy failed! "<< std::endl;
    }      
}
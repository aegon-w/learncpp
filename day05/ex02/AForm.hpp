/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:57:57 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/12 15:14:21 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool              signedAForm;
        int const         gradeToSign;
        int const         gradeToExecute;
    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &src);
        ~AForm();
        AForm &operator=(AForm const &rhs);

        std::string const   getName() const;
        bool                getSignedAForm() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        void                beSigned(Bureaucrat &bureaucrat);
        virtual void        execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:58:06 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/12 14:08:59 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool              signedForm;
        int const         gradeToSign;
        int const         gradeToExecute;
    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form const &src);
        ~Form();
        Form &operator=(Form const &rhs);

        std::string const   getName() const;
        bool                getSignedForm() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        void                beSigned(Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:14:32 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/15 11:25:37 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include "AForm.hpp"
#include <cstdlib>

class RobotmyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotmyRequestForm();
        RobotmyRequestForm(std::string target);
        RobotmyRequestForm(RobotmyRequestForm const &src);
        ~RobotmyRequestForm();
        RobotmyRequestForm &operator=(RobotmyRequestForm const &rhs);

        void execute(Bureaucrat const &executor) const;
};

#endif
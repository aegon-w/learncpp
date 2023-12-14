/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:10:54 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/14 18:52:32 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H   


# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

    private:
        std::string target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

        void execute(Bureaucrat const &executor) const;
};


#endif
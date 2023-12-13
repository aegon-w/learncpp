/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:03:21 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/13 17:24:03 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), target(src.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
        this->target = rhs.target;
    return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else
    {
        std::string filename = this->target + "_shrubbery";
        std::ofstream ofs(filename.c_str());
        if (ofs.is_open())
        {
            ofs << "          .     .  .      +     .      .          ." << std::endl;
            ofs << "     .       .      .     #       .           ." << std::endl;
            ofs << "        .      .         ###            .      .      ." << std::endl;
            ofs << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
            ofs << "          .      . \"####\"###\"####\"  ." << std::endl;
            ofs << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
            ofs << "  .             \"#########\"#########\"        .        ." << std::endl;
            ofs << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
            ofs << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
            ofs << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
            ofs << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
            ofs << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
            ofs << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
            ofs << "            .     \"      000      \"    .     ." << std::endl;
            ofs << "       .         .   .   000     .        .       ." << std::endl;
            ofs << ".. .. ..................O000O........................ ......" << std::endl;
            ofs.close();
        }
        else
            std::cout << "Error opening file" << std::endl;
    }
}


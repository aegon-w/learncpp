/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:00:45 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/03 19:45:55 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include <fstream>

PhoneBook::PhoneBook()
{
    this->nb_contacts = 0;
}

// PhoneBook::~PhoneBook()
// {
//     std::cout <<"PhoneBook destroyed ☠" << std::endl;
// }

void    PhoneBook::welcome()
{
    std::cout <<"----------------------- 📞----------------------" << std::endl;
    std::cout <<"Welcome to the PhoneBook!" << std::endl;
    std::cout <<"You can add a contact using <ADD> command." << std::endl;
    std::cout <<"You can search for a contact using <SEARCH> command."<<std::endl;
    std::cout <<"You can quit using <EXIT> command."<< std::endl;
    std::cout <<"-----------------------------------------------" << std::endl;
}

int main()
{
    PhoneBook phonebook;
    std::string input;
    
    phonebook.welcome();
    while (1)
    {
        std::cout << "Enter command: ";
        if (!(std::getline(std::cin, input)))
            return 1;    // why this doesn't work?(promped twice)
        // std::cin >> input;
        // if (is.eof())
        //     break;
        // std::cin.ignore(); // to ignore the newline character
        if (input == "EXIT")
        {
            std::cout << "Bye!" << std::endl;
            break;
        }
        else if (input == "ADD")
        {
            if (phonebook.add_contact())
                return 1;
        }
        else if (input == "SEARCH")
            phonebook.search_contact(phonebook);
    }
    return (0);
}
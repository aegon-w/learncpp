/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:00:45 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/29 18:39:24 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"



PhoneBook::PhoneBook()
{
    this->nb_contacts = 0;
}

int main()
{
    PhoneBook phonebook;
    std::string input;

    while (1)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, input);
        if (input == "EXIT")
            break;
        else if (input == "ADD")
        {
            phonebook.nb_contacts++;
            phonebook.add_contact();
        }
        else if (input == "SEARCH")
        {
            if (phonebook.nb_contacts == 0)
                std::cout << "No contacts to search" << std::endl;
            else
                phonebook.search_contact(phonebook);
        }
    }
    return (0);
}
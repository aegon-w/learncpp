/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:25:44 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/29 18:40:12 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
#include <iomanip>



void    PhoneBook::add_contact()
{
    Contact contact;
    PhoneBook phonebook;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    contact.set_first_name(input);
    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contact.set_last_name(input);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    contact.set_nickname(input);
    std::cout << "Enter index: ";
    std::getline(std::cin, input);
    contact.set_index(input);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contact.set_phone_number(input);
    std::cout << "Enter darkest secret : ";
    std::getline(std::cin, input);
    contact.set_darkest_secret(input);
}


void    PhoneBook::search_contact(PhoneBook phonebook)
{
    std::string input;
    int i;

    i = 0;
    while (i < phonebook.nb_contacts)
    {
        std::cout << "phonebook.contacts[i].name = " << phonebook.contacts[i].get_first_name() << std::endl;
        i++;
    }
    i = 0;
    while (i < phonebook.nb_contacts)
    {
        
        std::cout << std::setw(10) << phonebook.contacts[i].get_index() << "|";
        std::cout << std::setw(10) << phonebook.contacts[i].get_first_name() << "|";
        std::cout << std::setw(10) << phonebook.contacts[i].get_last_name() << "|";
        std::cout << std::setw(10) << phonebook.contacts[i].get_nickname() << std::endl;
        i++;
    }
    i = 0;
    
    while (i < phonebook.nb_contacts)
    {
        std::cout << "Enter index: ";
        std::getline(std::cin, input);
        std::cout << "input = " << input << std::endl;
        if (input == phonebook.contacts[i].get_index())
        {
            std::cout << "phonebook.contacts[i].get_first_name() = " << phonebook.contacts[i].get_first_name() << std::endl;
            std::cout << "First name: " << phonebook.contacts[i].get_first_name() << std::endl;
            std::cout << "Last name: " << phonebook.contacts[i].get_last_name() << std::endl;
            std::cout << "Nickname: " << phonebook.contacts[i].get_nickname() << std::endl;
            std::cout << "Index: " << phonebook.contacts[i].get_index() << std::endl;
            std::cout << "Phone number: " << phonebook.contacts[i].get_phone_number() << std::endl;
            std::cout << "Darkest secret: " << phonebook.contacts[i].get_darkest_secret() << std::endl;
            break;
        }
        i++;
    }   
}
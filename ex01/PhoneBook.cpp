/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:25:44 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/05 12:13:42 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
#include <iomanip>

int    PhoneBook::is_number(std::string str, std::string input)
{
    int i;

    i = 0;
    if (input.empty())
    {
        std::cout << "No " << str << " entered" << std::endl;
        return  1;
    }
    while (input[i])
    {
        if (!isdigit(input[i]))
        {
            std::cout << str << " error" << std::endl;
            return 1 ;
        }
        i++;
    }
    return 0;
}

int    PhoneBook::add_contact()
{
    std::string input;
    int current_index;
    current_index = this->nb_contacts % 8;
    std::cout << nb_contacts << "-----------"<< std::endl;
    this->contacts[current_index].set_index(current_index);
    std::cout << "Enter first name: ";
    if (!(std::getline(std::cin, input)))
        return 1;
    if (input.empty())
    {
        std::cout << "No first name entered" << std::endl;
        return 1;
    }
    this->contacts[current_index].set_first_name(input);
    std::cout << "Enter last name: ";
    if (!(std::getline(std::cin, input)))
        return 1;
    if (input.empty())
    {
        std::cout << "No last name entered" << std::endl;
        return 1;
    }
    this->contacts[current_index].set_last_name(input);
    std::cout << "Enter nickname: ";
    if (!(std::getline(std::cin, input)))
        return 1;
    if (input.empty())
    {
        std::cout << "No nickname entered" << std::endl;
        return 1;
    }
    this->contacts[current_index].set_nickname(input);
    std::cout << "Enter phone number: ";
    if (!(std::getline(std::cin, input)))
        return 1;
    if (is_number("phone number", input) == 1)
    {   
        return 1;
    }
    this->contacts[current_index].set_phone_number(input);
    std::cout << "Enter darkest secret : ";
    if (!(std::getline(std::cin, input)))
        return 1;
    if (input.empty())
    {
        std::cout << "No darkest secret entered" << std::endl;
        return 1;
    }
    this->contacts[current_index].set_darkest_secret(input);
    this->nb_contacts++;
    return 0;
}


void    PhoneBook::search_contact(PhoneBook phonebook)
{
    std::string input;
    int i;
    int arr[8];

    i = 0;
    int ret_count = phonebook.nb_contacts > 8 ? 8 : phonebook.nb_contacts;
    while (i < ret_count)
    {
        arr[i] = i;
        std::cout << std::setw(8) << arr[i] <<".|";
        if (phonebook.contacts[i].get_first_name().length() > 10)
            std::cout << std::setw(10) << phonebook.contacts[i].get_first_name().substr(0, 8) << ".|";
        else
            std::cout << std::setw(10) << phonebook.contacts[i].get_first_name() << ".|";
        if (phonebook.contacts[i].get_last_name().length() > 10)
            std::cout << std::setw(10) << phonebook.contacts[i].get_last_name().substr(0, 8) << ".|";
        else
            std::cout << std::setw(10) << phonebook.contacts[i].get_last_name() << ".|";
        if (phonebook.contacts[i].get_nickname().length() > 10)
            std::cout << std::setw(10) << phonebook.contacts[i].get_nickname().substr(0, 8) << ".|";
        else
            std::cout << std::setw(10) << phonebook.contacts[i].get_nickname() << ".|";
        if (phonebook.contacts[i].get_phone_number().length() > 10)
            std::cout << std::setw(10) << phonebook.contacts[i].get_phone_number().substr(0, 8) << ".|";
        else
            std::cout << std::setw(10) << phonebook.contacts[i].get_phone_number() << ".|";
        if (phonebook.contacts[i].get_darkest_secret().length() > 10)
            std::cout << std::setw(10) << phonebook.contacts[i].get_darkest_secret().substr(0, 8) << ".|";
        else
            std::cout << std::setw(10) << phonebook.contacts[i].get_darkest_secret() << std::endl;
        i++;
    }  
    std::cout << "Enter index: ";
    if (!(std::getline(std::cin, input)))
        return ;
    if (is_number("index", input) == 1)
        return ;
    i = 0;
    while(i < ret_count)
    {
        if (atoi(input.c_str()) > 7 || atoi(input.c_str()) < 0)
        {
            std::cout << "No contact with this index" << std::endl;
            return ;
        }
        if (atoi(input.c_str()) == arr[i])
        {
            std::cout << "First name:     " << phonebook.contacts[i].get_first_name() << std::endl;
            std::cout << "Last name:      " << phonebook.contacts[i].get_last_name() << std::endl;
            std::cout << "Nickname:       " << phonebook.contacts[i].get_nickname() << std::endl;
            std::cout << "Phone number:   " << phonebook.contacts[i].get_phone_number() << std::endl;
            std::cout << "Darkest secret: " << phonebook.contacts[i].get_darkest_secret() << std::endl;
            return ;
        }
        i++;
    }
}
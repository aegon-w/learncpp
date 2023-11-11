/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:24:38 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/11 11:52:17 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
#include <stdlib.h>
# include "./Contact.hpp"


class PhoneBook
{
    private:
        Contact contacts[8];
        int     nb_contacts;
    public:
        PhoneBook();
        ~PhoneBook();
        int    add_contact();
        void    search_contact(PhoneBook phonebook);
        int    is_number(std::string str, std::string input);
        void    welcome();
};


#endif
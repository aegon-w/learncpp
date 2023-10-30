/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:24:38 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/29 18:06:24 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "./Contact.hpp"

// void    add_contact();
// void    search_contact();

class PhoneBook
{
    public:
        Contact contacts[8];
        int     nb_contacts;
        PhoneBook();
        void    add_contact();
        void    search_contact(PhoneBook phonebook);
};


#endif
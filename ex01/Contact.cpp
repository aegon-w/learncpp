/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:58:31 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/29 18:39:30 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"

Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->index = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

std::string Contact::get_first_name()
{
    return (this->first_name);
}
std::string Contact::get_last_name()
{
    return (this->last_name);
}
std::string Contact::get_nickname()
{
    return (this->nickname);
}
std::string Contact::get_index()
{
    return (this->index);
}
std::string Contact::get_phone_number()
{
    return (this->phone_number);
}
std::string Contact::get_darkest_secret()
{
    return (this->darkest_secret);
}

void    Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}
void    Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}
void    Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}
void    Contact::set_index(std::string index)
{
    this->index = index;
}
void    Contact::set_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}
void    Contact::set_darkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}


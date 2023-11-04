/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:58:28 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/03 15:29:43 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string index;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact();
        // ~Contact();
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_index();
        std::string get_phone_number();
        std::string get_darkest_secret();
        void    set_first_name(std::string first_name);
        void    set_last_name(std::string last_name);
        void    set_nickname(std::string nickname);
        void    set_index(int index);
        void    set_phone_number(std::string phone_number);
        void    set_darkest_secret(std::string darkest_secret);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:39:56 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/10 16:32:57 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
# define REPLACE_H


#include <iostream>
#include <fstream>
#include <string>

class Replace
{
    private:
        std::string _filename;
    public:
        Replace();
        ~Replace();
        void replace(std::string filename, std::string s1,  std::string s2);
};

#endif
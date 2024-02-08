/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:26:58 by kali              #+#    #+#             */
/*   Updated: 2024/02/08 07:45:45 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <cstring>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange
{
    private:
        int _nDays;
        std::map<std::string, std::list<std::string> > _data;
        std::list<std::string> _headers;
        std::string _dataFile;
        std::string _inputFile;
        struct  tm _tm;
        
    public:
        BitcoinExchange(std::string const &file, std::string const &infile);
        ~BitcoinExchange(void);
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        void parseCSV(std::string const &file);
        void parseInput(std::string const &infile);
        int checkdate(std::string const &date);
        int checkprice(std::string const &price);
        std::string checkneardate(std::string & date);
};

#endif
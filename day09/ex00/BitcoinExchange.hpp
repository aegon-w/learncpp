/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:26:58 by kali              #+#    #+#             */
/*   Updated: 2024/01/30 10:13:27 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange
{
    private:
        int _nbDays;
        std::map<std::string, std::vector<std::string> > _data;
        std::vector<std::string> _headers;
        std::string _dataFile;
        std::string _inputFile;
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
        float run();
};

#endif
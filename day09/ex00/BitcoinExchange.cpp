/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:29:37 by kali              #+#    #+#             */
/*   Updated: 2024/02/08 07:46:16 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(std::string const &file, std::string const &infile)
{
    this->_dataFile = file;
    this->_inputFile = infile;
    this->parseCSV(file);
    this->parseInput(infile);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        this->_data = rhs._data;
        this->_headers = rhs._headers;
        this->_inputFile = rhs._inputFile;
    }
    return *this;
}

bool isleap(int year)
{
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

std::string int_to_string(int n)
{
    std::stringstream ss;
    ss << n;
    return (ss.str());
}

int BitcoinExchange::checkdate(std::string const &date)
{
    std::string year;
    std::string month;
    std::string day;
    std::string tmp;
    
    if (date.size() != 10)
        return 1;
    if (!strptime(date.c_str(), "%Y-%m-%d", &this->_tm))
        return 1;
    year = int_to_string(this->_tm.tm_year + 1900);
    month = int_to_string(this->_tm.tm_mon + 1);
    day = int_to_string(this->_tm.tm_mday);
    if (this->_tm.tm_mon + 1 == 2)
    {
        if (isleap(this->_tm.tm_year + 1900))
        {
            if (this->_tm.tm_mday > 29)
                return 1;
        }
        else if (this->_tm.tm_mday > 28)
            return 1;
    }
    return 0;
}

int BitcoinExchange::checkprice(std::string const &price)
{
    long  n = strtol(price.c_str(), NULL, 10);
    if (n < 0)
        {std::cout << "Error: not a positive number" << std::endl;
        return 1;}
    if (n > 100000)
        {std::cout << "Error: too large a number." << std::endl;
        return 1;}
    return 0;
}

void BitcoinExchange::parseCSV(std::string const &file)
{
    std::ifstream ifs(file.c_str());
    std::string line;
    std::string key;
    std::string value;
    
    if (!ifs.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return ;
    }
    getline(ifs, line);
    while (std::getline(ifs, line))
    {
        std::stringstream ss(line);
        std::getline(ss, key, ',');
        std::getline(ss, value, ',');
        this->_data[key].push_back(value);
    }
    ifs.close();
}

std::string BitcoinExchange::checkneardate(std::string & date)
{
        std::string nearestDate;
        int minDiff = 10000;
        for (std::map<std::string, std::list<std::string> >::iterator it = _data.begin(); it != _data.end(); ++it) {
            std::string dateKey = it->first;

            int yearInput, monthInput, dayInput;
            int yearKey, monthKey, dayKey;

            std::stringstream ssInput(date);
            ssInput >> yearInput >> monthInput >> dayInput;
            std::stringstream ssKey(dateKey);
            ssKey >> yearKey >> monthKey >> dayKey;

            int diff = std::abs(yearInput - yearKey) * 365 +
                        std::abs(monthInput - monthKey) * 30 +
                        std::abs(dayInput - dayKey);

            if (diff < minDiff) {
                minDiff = diff;
                nearestDate = dateKey;
            }
    }
    return nearestDate;
}
void    BitcoinExchange::parseInput(std::string const &_file)
{
    std::ifstream ifs(_file.c_str());
    std::string line;
    std::string key;
    std::string value;
    
    if (!ifs.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return ;
    }
    
    getline(ifs, line);
    while (std::getline(ifs, line))
    {
        std::stringstream ss(line);
        if (line.find('|') == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::getline(ss, key, '|');
        std::getline(ss, value, '|');
        key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
        value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
        if(checkdate(key))
        {
            std::cout << "Error: bad input => " << key << std::endl;
        }
        try
        {
            if(!checkprice(value))
            {
                if (this->_data.find(key) != this->_data.end())
                {
                    float price = atof(this->_data[key].front().c_str()) * atof(value.c_str());
                    std::cout << key << " => " << value << " = " << price << std::endl;
                    continue;
                }
                std::string near = checkneardate(key);
                float price = atof(this->_data[near].front().c_str()) * atof(value.c_str());
                std::cout << key << " => " << value << " = " << price << std::endl;
            }
            
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error" << '\n';
        }
    }

    ifs.close();
}

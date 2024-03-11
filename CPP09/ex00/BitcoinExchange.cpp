/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:29:37 by kali              #+#    #+#             */
/*   Updated: 2024/03/11 08:12:45 by xshel            ###   ########.fr       */
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
    if (n > 1000)
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

/*------------------------------------------------------------------*/

int check_char(const char *str, int i)
{
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            if (str[i] == '.')
                return (0);
            return (1);
        }
        i++;
    }
    return (0);
}

float ft_atof(const char *str)
{
    float res = 0.0;
    float sign = 1.0;
    int i = 0;
    if (str[0] == '-')
    {
        sign = -1.0;
        i++;
    }
    if (check_char(str, i))
        return (-1.0);
    for (; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            i++;
            float j = 0.1;
            for (; str[i] != '\0'; i++)
            {
                res += (str[i] - '0') * j;
                j *= 0.1;
            }
            break;
        }
        res = res * 10 + str[i] - '0';
    }
    return (res * sign);
}
/*------------------------------------------------------------------*/

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
                    float price = ft_atof(this->_data[key].front().c_str()) * ft_atof(value.c_str());
                    if (price < 0)
                    {
                        std::cout << "Error: bad input price => " << value << std::endl;
                        continue;
                    }
                    std::cout << key << " => " << value << " = " << price << std::endl;
                    continue;
                }
                std::string near = checkneardate(key);
                float price = ft_atof(this->_data[near].front().c_str()) * ft_atof(value.c_str());
                if (price < 0)
                {
                    std::cout << "Error: bad input price => " << value << std::endl;
                    continue;
                }
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:29:37 by kali              #+#    #+#             */
/*   Updated: 2024/01/30 10:01:00 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(std::string const &file, std::string const &infile)
{
    this->_dataFile = file;
    this->_inputFile = infile;
    this->_outputFile = infile + ".output";
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
        this->_nbDays = rhs._nbDays;
        this->_data = rhs._data;
        this->_headers = rhs._headers;
        this->_inputFile = rhs._inputFile;
        this->_outputFile = rhs._outputFile;
    }
    return *this;
}

int BitcoinExchange::checkdate(std::string const &date)
{
    std::string year;
    std::string month;
    std::string day;
    
    if (date.length() != 10)
        return 1;
    if (date[4] != '-' || date[7] != '-')
        return 1;
    year = date.substr(0, 4);
    std::cout << year << std::endl;
    month = date.substr(5, 2);
    std::cout << month << std::endl;
    day = date.substr(8, 2);
    std::cout << day << std::endl;
    if (atoi(year.c_str()) < 2009 || atoi(year.c_str()) > 2022)
        return 1;
    if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
        return 1;
    if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
        return 1;
    return 0;
}

int BitcoinExchange::checkprice(std::string const &price)
{
    int n = atoi(price.c_str());
    if (n < 0 || n > 10000)
        return 1;
    return 0;
}

void BitcoinExchange::parseCSV(std::string const &file)
{
    std::ifstream ifs(file.c_str());
    std::string line;
    std::string cell;
    std::vector<std::string> cells;
    std::vector<std::string> headers;
    std::map<std::string, std::vector<std::string> > data;
    std::string key;
    std::string value;
    
    if (!ifs.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return ;
    }
    
    //get headers
    std::getline(ifs, line);
    std::stringstream ss(line);
    while (std::getline(ss, cell, ','))
    {
        headers.push_back(cell);
    }
        
    //get data
    while (std::getline(ifs, line))
    {
        std::stringstream ss(line);
        while (std::getline(ss, cell, ','))
            cells.push_back(cell);
        for (int i = 0; i < (int)cells.size(); i++)
        {
            key = headers[i];
            value = cells[i];
            data[key].push_back(value);
            // std::cout << key << " " << value  << "/// "<< std::endl;
        }
        cells.clear();
    }
    
    ifs.close();
}

void    BitcoinExchange::parseInput(std::string const &_file)
{
    std::ifstream ifs(_file.c_str());
    std::string line;
    std::string cell;
    std::vector<std::string> cells;
    std::vector<std::string> headers;
    std::map<std::string, std::vector<std::string> > data;
    std::string key;
    std::string value;
    
    if (!ifs.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return ;
    }
    
    //get headers
    std::getline(ifs, line);
    std::stringstream ss(line);
    while (std::getline(ss, cell, '|'))
    {
        headers.push_back(cell);
    }
        
    //get data
    while (std::getline(ifs, line))
    {
        std::stringstream ss(line);
        while (std::getline(ss, cell, '|'))
            cells.push_back(cell);
        for (int i = 0; i < (int)cells.size(); i++)
        {   
            key = headers[i];
            value = cells[i];
            //chexk date and value
            std::cout << key << " " << value  << "/// "<< std::endl;
            value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
            if (i % 2 == 0)
            {
                if (this->checkdate(value))
                {
                    std::cout << value << std::endl;
                    std::cout << "Error: invalid date" << std::endl;
                    return ;
                }
            }
            else
            {
                if (this->checkprice(value))
                {
                    std::cout << "Error: invalid price" << std::endl;
                    return ;
                }
            }
        }
        cells.clear();
    }
    
    ifs.close();
}

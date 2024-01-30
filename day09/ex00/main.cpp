/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:21:57 by kali              #+#    #+#             */
/*   Updated: 2024/01/30 09:27:26 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./btc [file]" << std::endl;
        return 1;
    }
    BitcoinExchange bitcoinExchange("./data.csv", av[1]);
    //parse CSV file
    
    //parse input file
    // BitcoinExchange bitcoinExchange(av[1]);
}
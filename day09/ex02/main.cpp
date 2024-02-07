/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:12:04 by kali              #+#    #+#             */
/*   Updated: 2024/02/07 16:31:43 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeM.hpp"

int main(int ac, char **av)
{
    std::queue<int> _queue;
    std::list<int> _stack;
    std::vector<int> _res;
    int flag = 0;
    if (ac < 2)
    {
        std::cout << "Usage: ./pmergem [string]" << std::endl;
        return 1;
    }
    for (int i = 1; i < ac; i++)
    {
        if (ac % 2 == 0)
        {
            flag = 1;
        }
        std::string str = av[i];
        for (size_t j = 0; j < str.length(); j++)
        {
            if (isdigit(str[j]))
            {
                _queue.push(str[j] - '0');
                _stack.push_back(str[j] - '0');
                _res.push_back(str[j] - '0');
            }
            else if (str[j] == ' ')
                continue;
            else
            {
                std::cout << "Error: invalid input" << std::endl;
                return 1;
            }
        }
    }
    if (flag == 1)
    {
            _queue.push(-1);
            _stack.push_back(-1);
            _res.push_back(-1);
    }
    PmergeM pmergeM(_queue, _stack, _res);
    pmergeM.run();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:12:04 by kali              #+#    #+#             */
/*   Updated: 2024/02/07 17:02:33 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeM.hpp"

int main(int ac, char **av)
{
    std::deque<int> _deque;
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
        _deque.push_back(atoi(av[i]));
        _stack.push_back(atoi(av[i]));
        _res.push_back(atoi(av[i]));

    }
    if (flag == 1)
    {
            _deque.push_back(-1);
            _stack.push_back(-1);
            _res.push_back(-1);
    }
    PmergeM pmergeM(_deque, _stack, _res);
    pmergeM.run();
}
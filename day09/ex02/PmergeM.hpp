/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeM.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:31:53 by kali              #+#    #+#             */
/*   Updated: 2024/02/07 17:00:58 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEM_HPP
# define PMERGEM_HPP


#include <iostream>
#include <string>
#include <list>
#include <queue>
#include<deque>
#include <algorithm>
#include <iterator>
#include <cstdlib>

// template <typename T>

class PmergeM
{
    private:
        std::list<int> _stack;
        std::deque<int> _deque;
        std::vector<int> _res;
        std::string _str;
    public:
    
        PmergeM();
        PmergeM(std::deque<int> deque, std::list<int> stack, std::vector<int> res);
        ~PmergeM();
        void ford_johnson(std::deque<int> list);
        void _print();
        void run();
};


#endif
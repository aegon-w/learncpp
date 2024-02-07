/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeM.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:31:53 by kali              #+#    #+#             */
/*   Updated: 2024/02/07 16:36:48 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEM_HPP
# define PMERGEM_HPP


#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#include <iterator>

// template <typename T>

class PmergeM
{
    private:
        std::list<int> _stack;
        std::queue<int> _queue;
        std::vector<int> _res;
        std::string _str;
    public:
    
        PmergeM();
        PmergeM(std::queue<int> queue, std::list<int> stack, std::vector<int> res);
        ~PmergeM();
        void ford_johnson(std::queue<int> list);
        void _print();
        void run();
};


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeM.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:31:53 by kali              #+#    #+#             */
/*   Updated: 2024/02/08 12:23:54 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEM_HPP
# define PMERGEM_HPP


#include <iostream>
#include <string>
#include<deque>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

// template <typename T>

class PmergeM
{
    private:
        std::deque<int> _deque;
        std::vector<int> _res;
        std::string _str;
        double timeq;
        double timev;
        int ac;
    public:
    
        PmergeM();
        PmergeM(const PmergeM &src);
        PmergeM &operator=(const PmergeM &rhs);
        PmergeM(std::deque<int> deque, std::vector<int> res, int ac);
        ~PmergeM();
        void ford_johnson(std::deque<int> list);
        void ford_johnsonv(std::vector<int> vector);
        void run();
};


#endif
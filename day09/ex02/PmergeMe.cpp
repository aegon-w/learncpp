/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:34:39 by kali              #+#    #+#             */
/*   Updated: 2024/02/07 17:30:40 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeM.hpp"

PmergeM::PmergeM()
{
}

PmergeM::PmergeM(std::deque<int> deque, std::list<int> stack, std::vector<int> res)
{
    _deque = deque;
    _stack = stack;
    _res = res;
}

PmergeM::~PmergeM()
{
}

void PmergeM::run()
{
    // _print();
    ford_johnson(_deque);
}
// 3 5 9 8 4

// void PmergeM::_print()
// {
//     std::list<int>::iterator it = _stack.begin();
//     while (it != _stack.end())
//     {
//         std::cout << *it << " ";
//         it++;
//     }
//     std::cout << std::endl;
//     std::deque<int> _deque = this->_deque;
//     while (!_deque.empty())
//     {
//         std::cout << _deque.front() << " ";
//         _deque.pop();
//     }
//     std::cout << std::endl;
// }

bool compare(int a, int b) {
    return a > b; // Reversing the comparison logic for decreasing order
}

void merge_and_print(std::deque<int>& main, std::deque<int>& pend) {
    
    std::deque<int> merged;
    std::deque<int> main1 = main, pend1 = pend;
    while (!main1.empty()) {
        std::cout << main1.front() << " ";
        main1.pop_front();
    }
    std::cout << std::endl;
    while (!pend1.empty()) {
        std::cout << pend1.front() << " ";
        pend1.pop_front();
    }
    std::cout << std::endl;
    while (!pend.empty()) {
        int element = pend.front();
        pend.pop_front();

        // Use lower_bound to find the lower bound (insertion point) for the element
        std::deque<int>::iterator lower_bound_it = std::lower_bound(main.begin(), main.end(), element, compare);
        // upper bound
        // std::deque<int>::iterator upper_bound_it = std::upper_bound(main.begin(), main.end(), element);
        std::cerr << (*lower_bound_it) << " " << element << std::endl;
        main.insert(lower_bound_it, element);
    }

    // Print the merged deque
     while (!main.empty()) {
        std::cout << main.front() << " ";
        main.pop_front();
    }
    // std::cout << std::endl;
}

void PmergeM::ford_johnson(std::deque<int> deque)
{
    //divide to pairs
    std::deque<int> res;
    int size = deque.size();
    std::pair<int, int> pairs[size / 2];
    for (int i = 0; i < size / 2; i++)
    {
        // std::cout << deque.front() << " ";
        pairs[i].first = deque.front();
        deque.pop_front();
        // std::cout << deque.front() << std::endl;
        pairs[i].second = deque.front();
        deque.pop_front();
    }
    //sort pairs from highest to lowest
    for (int i = 0; i < size / 2; i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
   // Sort pairs in descending order of the first element
    std::sort(pairs, pairs + size / 2, std::greater<std::pair<int, int> >());
    // Print the sorted pairs
    // for (int i = 0; i < size / 2; i++) {
    //     std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
    // }
    //divide pairs in two groups (main and pend)
    std::deque<int> main;
    std::deque<int> pend;
    for (int i = 0; i < size / 2; i++)
    {
        // std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    //merge main and pend using lower bound  
    merge_and_print(main, pend);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:34:39 by kali              #+#    #+#             */
/*   Updated: 2024/02/07 16:46:08 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeM.hpp"

PmergeM::PmergeM()
{
}

PmergeM::PmergeM(std::queue<int> queue, std::list<int> stack, std::vector<int> res)
{
    _queue = queue;
    _stack = stack;
    _res = res;
}

PmergeM::~PmergeM()
{
}

void PmergeM::run()
{
    // _print();
    ford_johnson(_queue);
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
//     std::queue<int> _queue = this->_queue;
//     while (!_queue.empty())
//     {
//         std::cout << _queue.front() << " ";
//         _queue.pop();
//     }
//     std::cout << std::endl;
// }

void merge_and_print(std::queue<int>& main, std::queue<int>& pend) {
    std::queue<int> merged;

    while (!pend.empty()) {
        int element = pend.front();
        pend.pop();

        // Use a loop to find the insertion point within the main queue
        int i = 0;
        bool inserted = false;
        while (!main.empty() && !inserted) {
            if (main.front() < element) {
                merged.push(main.front());
                main.pop();
                i++;
            } else {
                inserted = true;
            }
        }
        merged.push(element);

        // Push back remaining elements from main
        while (!main.empty()) {
            merged.push(main.front());
            main.pop();
        }
    }
    // Print the merged queue
    while (!merged.empty()) {
        std::cout << merged.front() << " ";
        merged.pop();
    }
    std::cout << std::endl;
}

void PmergeM::ford_johnson(std::queue<int> queue)
{
    //divide to pairs
    std::queue<int> res;
    int size = queue.size();
    std::pair<int, int> pairs[size / 2];
    for (int i = 0; i < size / 2; i++)
    {
        // std::cout << queue.front() << " ";
        pairs[i].first = queue.front();
        queue.pop();
        // std::cout << queue.front() << std::endl;
        pairs[i].second = queue.front();
        queue.pop();
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
    std::queue<int> main;
    std::queue<int> pend;
    for (int i = 0; i < size / 2; i++)
    {
        main.push(pairs[i].first);
        pend.push(pairs[i].second);
    }
    //merge main and pend using lower bound  
    merge_and_print(main, pend);
}
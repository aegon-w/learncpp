/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:34:39 by kali              #+#    #+#             */
/*   Updated: 2024/02/08 12:22:44 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeM.hpp"

PmergeM::PmergeM()
{
}

PmergeM::PmergeM(std::deque<int> deque, std::vector<int> res, int ac)
{
    _deque = deque;
    _res = res;
    this->ac = ac;
}

PmergeM::~PmergeM()
{
}

PmergeM::PmergeM(const PmergeM &src)
{
    *this = src;
}

PmergeM &PmergeM::operator=(const PmergeM &rhs)
{
    if (this != &rhs)
    {
        this->_deque = rhs._deque;
        this->_res = rhs._res;
    }
    return *this;
}

void PmergeM::run()
{
    // _print();
    clock_t start, end;
    start = clock();
    ford_johnson(_deque);
    end = clock();
    std::cout << end - start << std::endl;
    this->timeq = (double)(end - start) / 1000000.0 ;
    start = clock();
    ford_johnsonv(_res);
    end = clock();
    std::cout << end - start << std::endl;

    this->timev = (double)(end - start) / 1000000.0 ;
    std::cout << "Time to process a range of " << this->ac - 1 <<" elements with std::[queue] :"<< this->timeq  << " in us"<< std::endl;
    std::cout << "Time to process a range of " << this->ac - 1 <<" elements with std::[vector] :"<< this->timev  << " in us"<< std::endl;
}
// 3 5 9 8 4



bool compare(int a, int b) {
    return a > b; // Reversing the comparison logic for decreasing order
}

void merge_and_print(std::deque<int>& main, std::deque<int>& pend) {
    
    while (!pend.empty()) {
        int element = pend.front();
        pend.pop_front();
        // Use lower_bound to find the lower bound (insertion point) for the element
        std::deque<int>::iterator lower_bound_it = std::lower_bound(main.begin(), main.end(), element, compare);
        main.insert(lower_bound_it, element);
    }

    if (main.back() == -1)
        main.pop_back();
    std::cout << "After(deque): ";
    while (!main.empty())
    {
        std::cout << main.front() << " ";
        main.pop_front();
    }
    std::cout << std::endl;
}

void PmergeM::ford_johnson(std::deque<int> deque)
{
    //divide to pairs
    std::deque<int> res;
    int size = deque.size();
    std::pair<int, int> pairs[size / 2];
    for (int i = 0; i < size / 2; i++)
    {
        pairs[i].first = deque.front();
        deque.pop_front();
        pairs[i].second = deque.front();
        deque.pop_front();
    }
    //sort pairs from highest to lowest recursively
    for (int i = 0; i < size / 2; i++)
    {
        // sortpairs(pairs[i], size / 2);
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
   // Sort pairs in descending order of the first element
    std::sort(pairs, pairs + size / 2, std::greater<std::pair<int, int> >());
    //divide pairs in two groups (main and pend)
    std::deque<int> main;
    std::deque<int> pend;
    for (int i = 0; i < size / 2; i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    //merge main and pend using lower bound  
    merge_and_print(main, pend);
}

void merge_and_printv(std::vector<int>& main, std::vector<int>& pend) {
    
    while (!pend.empty()) {
        int element = pend.front();
        pend.erase(pend.begin());
        // Use lower_bound to find the lower bound (insertion point) for the element
        std::vector<int>::iterator lower_bound_it = std::lower_bound(main.begin(), main.end(), element, compare);
        main.insert(lower_bound_it, element);
    }

    if (main.back() == -1)
        main.pop_back();
    std::cout << "After(vector): ";
    while (!main.empty())
    {
        std::cout << main.front() << " ";
        main.erase(main.begin());
    }
    std::cout << std::endl;
}

void PmergeM::ford_johnsonv(std::vector<int> vector)
{
    //divide to pairs
    std::vector<int> res;
    int size = vector.size();
    std::pair<int, int> pairs[size / 2];
    for (int i = 0; i < size / 2; i++)
    {
        pairs[i].first = vector.front();
        vector.erase(vector.begin());
        pairs[i].second = vector.front();
        vector.erase(vector.begin());
    }
    //sort pairs from highest to lowest recursively
    for (int i = 0; i < size / 2; i++)
    {
        // sortpairs(pairs[i], size / 2);
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
   // Sort pairs in descending order of the first element
    std::sort(pairs, pairs + size / 2, std::greater<std::pair<int, int> >());
    //divide pairs in two groups (main and pend)
    std::vector<int> main;
    std::vector<int> pend;
    for (int i = 0; i < size / 2; i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    //merge main and pend using lower bound  
    merge_and_printv(main, pend);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:20:30 by xshel             #+#    #+#             */
/*   Updated: 2024/01/22 07:36:46 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _v;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &obj);
        ~Span();
        Span &operator=(const Span &obj);
        
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        
        class NoSpaceException : public std::exception
        {
            virtual const char *what() const throw();
        };
        class NoSpanException : public std::exception
        {
            virtual const char *what() const throw();
        };
};



#endif
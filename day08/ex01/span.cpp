/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:22:14 by xshel             #+#    #+#             */
/*   Updated: 2024/01/22 07:36:37 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
{
    _n = 0;
}

Span::Span(unsigned int n)
{
    _n = n;
}

Span::Span(const Span &obj)
{
    *this = obj;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &obj)
{
    if(this == &obj)
    _n = obj._n;
    _v = obj._v;
    return (*this);
}

void Span::addNumber(int n)
{
    if (_v.size() < _n)
        _v.push_back(n);
    else
        throw NoSpaceException();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_v.size() + std::distance(begin, end) <= _n)
        _v.insert(_v.end(), begin, end);
    else
        throw NoSpaceException();
}

int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw NoSpanException();
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 2; i < tmp.size(); i++)
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    return (min);
}

int Span::longestSpan()
{
    if (_v.size() < 2)
        throw NoSpanException();
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::NoSpaceException::what() const throw()
{
    return ("No space");
}

const char *Span::NoSpanException::what() const throw()
{
    return ("No span");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:32:46 by kali              #+#    #+#             */
/*   Updated: 2024/02/04 04:48:58 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _input("")
{
}

RPN::RPN(std::string input) : _input(input)
{
}

RPN::RPN(const RPN &rpn)
{
    *this = rpn;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &rpn)
{
    if (this != &rpn)
    {
        this->_input = rpn._input;
        this->_stack = rpn._stack;
    }
    return *this;
}

int operate(std::string op, std::stack<int> &stack)
{
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    if (op == "+")
        return b + a;
    else if (op == "-")
        return b - a;
    else if (op == "*")
        return b * a;
    else if (op == "/")
        return b / a;
    else if (op == "%")
        return b % a;
    return 0;
}

void RPN::run()
{
    std::istringstream iss(_input);
    std::string token;
    while (std::getline(iss, token, ' '))
    {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
            _stack.push(operate(token, _stack));
        else
        {
            if (token == "(" || token == ")")
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            _stack.push(atoi(token.c_str()));
        }
    }
    std::cout << _stack.top() << std::endl;
}



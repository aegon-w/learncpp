/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:55:29 by kali              #+#    #+#             */
/*   Updated: 2024/02/04 04:43:59 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int> _stack;
        std::string _input;
    public:
        RPN();
        RPN(std::string input);
        RPN(const RPN &rpn);
        RPN &operator=(const RPN &rpn);
        ~RPN();
        void run();
     
          
};



#endif
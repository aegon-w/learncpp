/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 05:50:33 by kali              #+#    #+#             */
/*   Updated: 2024/01/24 09:36:49 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP


# include <iostream>
# include <stack>
# include <deque>


template <typename T, class Container = std::deque< T > >

class MutantStack : public std::stack<int>
{
    public:
        MutantStack(){};
        MutantStack(MutantStack const &other){(void)other;};
        MutantStack &operator=(MutantStack const &other){(void)other;return (*this);};
        ~MutantStack(){};

        typedef std::deque<int>::iterator iterator;
        iterator begin(){return (iterator(this->c.begin()));};
        iterator end(){return (iterator(this->c.end()));};
};



#endif
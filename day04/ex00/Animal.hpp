/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:51:32 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/04 14:51:34 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &obj);
        Animal &operator=(const Animal &obj);
        // Animal(std::string type);
        virtual ~Animal();// pour que le destructeur de la classe enfant soit appele
        virtual void makeSound() const;
        std::string getType() const;
};


#endif
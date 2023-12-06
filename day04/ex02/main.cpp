/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:53:09 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/05 17:32:40 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Dog.hpp"
// #include "Cat.hpp"

// #include "WrongCat.hpp"

// /*
//     The order of constructor and destructor:
//         1. Base constructor
//         2. Derived constructor
//         3. Derived destructor
//         4.Base destructor
// */

// int main( void )
// {

//     // Animal* meta = new Animal();
    
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     delete j;//should not create a leak
//     delete i;

//     Dog basic;
//     {
//         Dog tmp = basic;
//     }

//     const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
//     for ( int i = 0; i < 4; i++ ) {
//         delete animals[i];
//     }

//     return 0;
// }

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ARRAY_SIZE 10


int main()
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }

    {
        Animal *zoo[ARRAY_SIZE];

        for (size_t i = 0; i < ARRAY_SIZE; i++)
        {
            if (i % 2) zoo[i] = new Dog();
            else zoo[i] = new Cat();
        }

        for (size_t i = 0; i < ARRAY_SIZE; i++)
            delete zoo[i];
    }

    {
        Cat kitten = Cat();
        Cat cat (kitten);

        Brain * kittenBrain = kitten.getBrain();
        Brain * catBrain = cat.getBrain();

        kittenBrain->setIdea(0, "thinking about baby stuff");
        catBrain->setIdea(0, "thinking about adult stuff");


        std::cout << kittenBrain->getIdea(0) << std::endl;
        std::cout << catBrain->getIdea(0) << std::endl;
    }
    return 0;
}
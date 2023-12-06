/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:53:00 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/05 14:53:36 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP 

# include <iostream>
# include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inventory[4];
        int count;
    public:
        Character();
        Character(std::string name);
        Character(Character const &src);
        ~Character();

        Character &operator=(Character const &rhs);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
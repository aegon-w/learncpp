/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:19:16 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/01 15:08:48 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public: 
        ScavTrap();
        ~ScavTrap();
        ScavTrap(ScavTrap const &src);
        ScavTrap &operator=(ScavTrap const &rhs);
        ScavTrap(std::string name);
        void attack(const std::string & target);
        void guardGate();
};





#endif
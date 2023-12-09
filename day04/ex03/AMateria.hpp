/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:07:53 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/09 10:34:06 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"


class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(AMateria const &src);
        AMateria &operator=(AMateria const &rhs);
        virtual ~AMateria();
        
        AMateria(std::string const & type);
        
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
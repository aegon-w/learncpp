/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:27 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/05 14:52:32 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *materia[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource const &src);
        ~MateriaSource();

        MateriaSource &operator=(MateriaSource const &rhs);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};



#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:42 by m-boukel          #+#    #+#             */
/*   Updated: 2023/12/18 15:29:26 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <cinttypes>uintptr_t
uintptr_t
uintptr_tuintptr_t
uintptr_t
uintptr_t

int main()
{
    srand(time(NULL));
    Data *data = deserialize(serialize(new Data));
    std::cout << data->s1 << std::endl;
    std::cout << data->n << std::endl;
    delete data;
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:17:46 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/29 14:18:10 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
  int i;
  int j;

  i = 1;
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else
  {
    while (i < argc)
    {
      j = 0;
      while (argv[i][j])
      {
        std::cout << (char)toupper(argv[i][j]);
        j++;
      }
      i++;
    }
  }
  std::cout << std::endl;
  return (0);
}
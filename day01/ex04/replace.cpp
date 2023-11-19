/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:40:49 by m-boukel          #+#    #+#             */
/*   Updated: 2023/11/19 16:51:03 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <iostream>
#include <fstream>

Replace::Replace()
{
}

Replace::~Replace()
{
}

void Replace::replace(std::string filename,std::string s1, std::string s2)
{
  std::ifstream ifs(filename.c_str());
  if (!ifs.is_open())
  {
    std::cerr << "Error: could not open input file " << filename << std::endl;
    return;
  }

  std::ofstream ofs(filename.append(".replace").c_str());
  if (!ofs.is_open())
  {
    std::cerr << "Error: could not open output file " << filename << ".replace" << std::endl;
    return;
  }

  std::string line;
  while (std::getline(ifs, line) && !ifs.eof())
  {
    while (line.find(s1) != std::string::npos)
    {
      std::size_t pos = line.find(s1);
      line.erase(pos, s1.length());
      line.insert(pos, s2);
    }
    ofs << line << std::endl;
  }
  ifs.close();
  ofs.close();
}

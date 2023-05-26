/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:19:31 by averdon           #+#    #+#             */
/*   Updated: 2023/03/17 14:35:30 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	replace(std::ifstream *infile, std::ofstream *outfile,
	std::string str_to_add, std::string str_to_suppress)
{
	std::string		line;
	int 			index;
	
	while (std::getline(*infile, line))
	{
		index = 0;
		while (line.find(str_to_suppress, index) != std::string::npos)
		{
			index = line.find(str_to_suppress, index);
			line.erase(index, str_to_suppress.length());
			line.insert(index, str_to_add);
			index += str_to_add.length();
		}
		*outfile << line << "\n";
	}
}

void	create_file(char **argv, std::ifstream *infile)
{
	std::string 	str_to_suppress;
	std::string 	str_to_add;
	std::string 	new_file;

	str_to_suppress = argv[2];
	if (str_to_suppress == "")
		return ;
	str_to_add = argv[3];
	new_file = argv[1];
	new_file.append(".replace");
	std::ofstream	outfile (new_file.c_str());
	replace(infile, &outfile, str_to_add, str_to_suppress);
	infile->close();
	outfile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "wrong numbers of arguments\n";
		return (1);
	}
	std::ifstream	infile (argv[1]);
	if (infile.is_open())
		create_file(argv, &infile);
	else
		std::cout << "invalid filename\n";
	return (0);
}

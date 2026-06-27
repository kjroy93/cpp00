/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:58:44 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/27 03:37:25 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	int			size;
	std::string	command;

	pb.setIndex(0);
	while (true)
	{
		if (std::cin.eof())
			break ;
		std::cout << "Please enter a valid command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
		{
			size = pb.getIndex();
			if (size > 8)
				size = 8;
			pb.search(size);
		}
		else if (command == "EXIT")
			break ;
		else
			continue ;
	}
	return (0);
}

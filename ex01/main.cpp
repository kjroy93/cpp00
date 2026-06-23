/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:58:44 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/23 19:40:49 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	pb;
	int			size;
	std::string	command;

	pb.setIndex(0);
	while (true)
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "Please enter a valid command: ADD, SEARCH or EXIT" << std::endl;
		std::cin >> command;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(255, '\n');
			continue ;
		}
		else if (command == "ADD")
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

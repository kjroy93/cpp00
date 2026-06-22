/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:58:44 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/22 20:26:34 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	command;
	int			i;
	int			size;

	i = 0;
	size = 0;
	pb.setIndex(i);
	while (true)
	{
		std::cout << "Please enter a valid command: ADD, SEARCH or EXIT" << std::endl;
		std::cin >> command;
		if (command == "ADD")
		{
			pb.addContact();
			i += 1;
			if (size < 8)
				size++;
			pb.setIndex(i);
		}
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT")
			break ;
		else
			continue ;
	}
}

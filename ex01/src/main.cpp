/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:58:44 by kjroydev          #+#    #+#             */
/*   Updated: 2026/05/24 21:31:18 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	command;
	int			i;
	int			size;

	i = 0;
	size = 0;
	pb.set_index(i);
	while (true)
	{
		std::cout << "Please enter a valid command: ADD, SEARCH or EXIT" << std::endl;
		std::cin >> command;
		if (command == "ADD")
		{
			pb.add_contact();
			i += 1;
			if (size < 8)
				size++;
			pb.set_index(i);
		}
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT")
			break ;
		else
			continue ;
	}
}

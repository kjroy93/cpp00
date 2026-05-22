/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:27:44 by kjroydev          #+#    #+#             */
/*   Updated: 2026/05/22 20:58:13 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	PhoneBook::getIndex()
{
	return (i);
}

void	PhoneBook::setIndex(int num)
{
	i = num;
}

void	PhoneBook::search()
{
	
}

void	PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string number;
	std::string secret;

	contacts_[i].setContact(
		first_name,
		last_name,
		nick_name,
		number,
		secret
	);	
}
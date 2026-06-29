/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:36:50 by kmarrero          #+#    #+#             */
/*   Updated: 2026/06/29 12:36:52 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::getIndex()
{
	return (this->i);
}

void	PhoneBook::setIndex(int num)
{
	this->i = num;
}

std::string	PhoneBook::cleanIndex(int i)
{
	std::string			s;
	std::stringstream	index;

	index << i + 1;
	s = index.str();
	return (s);
}

std::string	PhoneBook::format(std::string info)
{
	std::string	word;
	size_t		str_len;

	str_len = info.size();
	if (str_len > 9)
	{
		word = info.substr(0, 9);
		word.append(".");
		return (word);
	}
	return (info);
}

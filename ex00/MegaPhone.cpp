/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:11:15 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/27 01:25:16 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	std::string	str;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (size_t j = 0; j < str.size(); j++)
		{
			str[j] = static_cast<char>(
				std::toupper(static_cast<unsigned char>(str[j]))
			);
		}
		std::cout << str;
		if (i + 1 < argc)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}

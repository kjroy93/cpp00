/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:11:15 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/10 19:56:45 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	int		i;
	size_t	j;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			std::string str = argv[i];
			while (j < str.size())
			{
				str[j] = (char)std::toupper(str[j]);
				j++;
			}
			std::cout << str << std::endl;
			i++;
		}
	}
	return (0);
}

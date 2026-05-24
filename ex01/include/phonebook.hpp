/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:37:14 by kjroydev          #+#    #+#             */
/*   Updated: 2026/05/24 22:25:03 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
# define PHONEBOOK
# include "contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>

class PhoneBook
{
	private:
		int			i;
		Contact 	contacts_[8];
		void		table(int &n);
		std::string	format(std::string);
		std::string clean_index(int i);
	public:
		void	search(void);
		int		get_index(void);
		void	add_contact(void);
		void	set_index(int num);
		void	print(const std::string &s);
		void	print_row(int i, std::string command);
};

#endif
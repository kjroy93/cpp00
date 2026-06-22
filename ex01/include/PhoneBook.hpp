/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:37:14 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/22 20:21:04 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
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
		std::string cleanIndex(int i);
	public:
		void	search(void);
		int		getIndex(void);
		void	addContact(void);
		void	setIndex(int num);
		void	print(const std::string &s);
		void	printRow(int i, std::string command);
};

#endif
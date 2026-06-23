/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:37:14 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/23 19:34:34 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstdlib>

class PhoneBook
{
	private:
		int			i;
		Contact 	contacts_[8];
		void		table(int size);
		std::string cleanIndex(int i);
		std::string	format(std::string);
	public:
		int		getIndex(void);
		void	eofCheck(void);
		void	search(int size);
		void	addContact(void);
		void	setIndex(int num);
		void	printResult(int i);
		void	print(const std::string& s);
		void	printColumn(const std::string& c);
		void	printRow(int i, std::string command);
};

#endif
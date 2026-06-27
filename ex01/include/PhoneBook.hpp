/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:37:14 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/27 16:24:24 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
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
		void		printResult(int i);
		std::string	format(std::string info);
		void		print(const std::string& s);
		bool		isValidEntry(std::string& entry);
		void		printColumn(const std::string& c);
		void		printRow(int i, std::string command);
		bool		processEntry(const std::string& prompt, std::string& entry);
		bool		processNumber(const std::string& prompt, std::string& number);
	public:
		int			getIndex(void);
		void		search(int size);
		void		addContact(void);
		void		setIndex(int num);
};

#endif
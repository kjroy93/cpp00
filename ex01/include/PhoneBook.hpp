/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:37:14 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/26 22:19:37 by kmarrero         ###   ########.fr       */
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
		std::string	format(std::string info);
		std::string	processEntry(const std::string& prompt, std::string& entry);
		std::string	processNumber(const std::string& prompt);
		void		printResult(int i);
		void		print(const std::string& s);
		void		printColumn(const std::string& c);
		void		printRow(int i, std::string command);
		bool		isValidEntry(std::string& entry);
	public:
		int			getIndex(void);
		void		eofCheck(void);
		void		search(int size);
		void		addContact(void);
		void		setIndex(int num);

};

#endif
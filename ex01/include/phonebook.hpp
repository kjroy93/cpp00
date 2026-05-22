/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:37:14 by kjroydev          #+#    #+#             */
/*   Updated: 2026/05/22 20:48:31 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact contacts_[8];
		int		i = 0;
	public:
		void	add_contact();
		void	table(int &i);
		void	search();
		void	print(const Contact &c);
		void	setIndex(int num);
		int		getIndex();
};

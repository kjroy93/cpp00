/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:37:19 by kjroydev          #+#    #+#             */
/*   Updated: 2026/05/24 21:05:47 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
# define CONTACT
# include <iostream>
# include <string>

class Contact
{
	private:
		std::string secret_;
		std::string last_name_;
		std::string nick_name_;
		std::string first_name_;
		std::string phone_number_;
	public:
		void	set_contact(
				const std::string &first_name,
				const std::string &last_name,
				const std::string &nickname,
				const std::string &num,
				const std::string &secret);
		const std::string& get_number() const;
		const std::string& get_secret() const;
		const std::string& get_nickname() const;
		const std::string& get_last_name() const;
		const std::string& get_first_name() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:37:19 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/22 20:59:13 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
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
		void	setContact(
				const std::string &first_name,
				const std::string &last_name,
				const std::string &nickname,
				const std::string &num,
				const std::string &secret);
		const std::string& getNumber() const;
		const std::string& getSecret() const;
		const std::string& getNickName() const;
		const std::string& getLastName() const;
		const std::string& getFirstName() const;
};

#endif
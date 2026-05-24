/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 19:06:42 by kjroydev          #+#    #+#             */
/*   Updated: 2026/05/24 20:56:01 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	Contact::set_contact(
				const std::string &first_name,
				const std::string &last_name,
				const std::string &nickname,
				const std::string &num,
				const std::string &secret)
{
	first_name_ = first_name;
	last_name_ = last_name;
	nick_name_ = nickname;
	phone_number_ = num;
	secret_ = secret;
}

const std::string& Contact::get_first_name(void) const
{
	return (first_name_);
}

const std::string& Contact::get_last_name(void) const
{
	return (last_name_);
}

const std::string& Contact::get_nickname(void) const
{
	return (nick_name_);
}

const std::string& Contact::get_number(void) const
{
	return (phone_number_);
}

const std::string& Contact::get_secret(void) const
{
	return (secret_);
}

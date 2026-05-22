/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 19:06:42 by kjroydev          #+#    #+#             */
/*   Updated: 2026/05/22 20:42:56 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	Contact::setContact(
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

const std::string& Contact::getFirstName() const
{
	return (first_name_);
}

const std::string& Contact::getLastName() const
{
	return (last_name_);
}

const std::string& Contact::getNickName() const
{
	return (nick_name_);
}

const std::string& Contact::getNumber() const
{
	return (phone_number_);
}

const std::string& Contact::getSecret() const
{
	return (secret_);
}


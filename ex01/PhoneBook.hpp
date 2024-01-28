/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:23:46 by bcastelo          #+#    #+#             */
/*   Updated: 2024/01/28 19:40:38 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

#define MAX_CONTACTS 8

class PhoneBook
{
	Contact		contacts[MAX_CONTACTS];
	public:
		void	add();
		void	print(int index);
		void	print_list();
};

#endif
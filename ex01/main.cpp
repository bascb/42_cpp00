/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:56:31 by bcastelo          #+#    #+#             */
/*   Updated: 2024/02/05 19:06:11 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	welcome_message();

int	main()
{
	PhoneBook	list;
	std::string	command;
	int			index;
	
	welcome_message();
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		if (command == "ADD")
			list.add();
		else if (command == "SEARCH")
		{
			list.print_list();
			index = list.get_index();
			if (index >= 0)
				list.print(index);
		}
		else if (command == "EXIT")
			return (0);
	}
	return (0);
}

void	welcome_message()
{
	std::cout << "Welcome to your Electronic Phone book!" << std::endl;
	std::cout << "Phone book capacity:" << MAX_CONTACTS << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "ADD - Add a new contact" << std::endl;
	std::cout << "SEARCH - Search for a specific contact " << std::endl;
	std::cout << "EXIT - Close application " << std::endl;
}
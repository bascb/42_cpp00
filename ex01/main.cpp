/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:56:31 by bcastelo          #+#    #+#             */
/*   Updated: 2024/01/31 20:29:38 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	list;
	std::string	command;
	int			index;
	
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
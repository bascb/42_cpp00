/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:56:31 by bcastelo          #+#    #+#             */
/*   Updated: 2024/01/28 22:44:34 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	list;
	std::string	command;
	
	while (1)
	{
		std::cout << "> ";
		std::cin >> command;
		if (command == "ADD")
			list.add();
		else if (command == "SEARCH")
			list.print_list();
		else if (command == "EXIT")
			return (0);
		std::cin.clear();
	}
	return (0);
}
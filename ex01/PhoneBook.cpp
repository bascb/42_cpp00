/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:43:58 by bcastelo          #+#    #+#             */
/*   Updated: 2024/01/28 22:44:55 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	fill_field(std::string label);

void	PhoneBook::add()
{
	static int	i = 0;
	
	std::cout << "Please fill in the fields, one by one. There cannot be blank fields." << std::endl;
	contacts[i].first_name = fill_field("First name:");
	contacts[i].last_name = fill_field("Last name:");
	contacts[i].nickname = fill_field("Nickname:");
	contacts[i].phone_number = fill_field("Phone number:");
	contacts[i].darkest_secret = fill_field("Darkest secret:");
	if (i + 1 == MAX_CONTACTS)
		i = 0;
	else
		i++;
}

void	PhoneBook::print(int index)
{
	std::cout << "First name: " << contacts[index].first_name << std::endl;
	std::cout << "Last name: " << contacts[index].last_name << std::endl;
	std::cout << "Nickname: " << contacts[index].nickname << std::endl;
	std::cout << "Phone number: " << contacts[index].phone_number << std::endl;
	std::cout << "Darkest secret: " << contacts[index].darkest_secret << std::endl;
}

void	PhoneBook::print_list()
{
	int	index;
	
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << std::setw(11);
		std::cout << i << "|";
		std::cout << contacts[i].first_name << "|";
		std::cout << contacts[i].last_name << "|";
		std::cout << contacts[i].nickname << "|";
		std::cout << contacts[i].phone_number << "|";
		std::cout << contacts[i].darkest_secret << "|";
		std::cout << std::endl;
	}
	std::cout << "Enter desired contact index:";
	std::cin >> index;
	if (index >= 0 && index < MAX_CONTACTS)
		print(index);
}

std::string	fill_field(std::string label)
{
	std::string	answer;
	
	while (answer.empty())
	{
		std::cout << label;
		std::cin >> answer;
		std::cin.clear();
	}
	return (answer);
}
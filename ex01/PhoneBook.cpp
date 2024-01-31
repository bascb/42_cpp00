/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:43:58 by bcastelo          #+#    #+#             */
/*   Updated: 2024/01/31 20:32:39 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	fill_field(std::string label);

void	print_cell(std::string str);

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
	if (contacts[0].first_name.empty())
	{
		std::cout << "The Phone book is empty!" << std::endl;
		return ;
	}
	print_cell("index");
	print_cell("first name");
	print_cell("last name");
	print_cell("nickname");
	std::cout << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (!contacts[i].first_name.empty())
		{
			std::cout << std::setw(10);
			std::cout << i << "|";
			print_cell(contacts[i].first_name);
			print_cell(contacts[i].last_name);
			print_cell(contacts[i].nickname);	
			std::cout << std::endl;
		}
	}
}

int	PhoneBook::get_index()
{
	int	index;
	int	max;

	max = 0;
	while (!contacts[max].first_name.empty() && max < MAX_CONTACTS)
		max++;
	max--;
	if (max == -1)
		return (max);
	while (1)
	{
		std::cout << "Enter the index of the desired contact: ";
		if (std::cin >> index && index >= 0 && index <= max)
		{
			std::cin.ignore();
			break;
		}
		else
		{
			std::cout << "Must be an integer between 0 and " << max << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}	
	}
	return (index);
}

std::string	fill_field(std::string label)
{
	std::string	answer;
	
	while (answer.empty())
	{
		std::cout << label;
		std::getline(std::cin, answer);
	}
	return (answer);
}

void	print_cell(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10);
	std::cout << str << "|";
}
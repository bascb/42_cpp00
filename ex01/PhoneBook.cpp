/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:43:58 by bcastelo          #+#    #+#             */
/*   Updated: 2024/02/05 19:03:20 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	fill_field(std::string label);

void	print_cell(std::string str);

void	PhoneBook::add()
{
	static int	i = 0;
	
	std::cout << "Please fill in the fields, one by one. There cannot be blank fields." << std::endl;
	contacts[i].set_field("first name", fill_field("First name:"));
	contacts[i].set_field("last name", fill_field("Last name:"));
	contacts[i].set_field("nickname", fill_field("Nickname:"));
	contacts[i].set_field("phone number", fill_field("Phone number:"));
	contacts[i].set_field("darkest secret", fill_field("Darkest secret:"));
	if (i + 1 == MAX_CONTACTS)
		i = 0;
	else
		i++;
}

void	PhoneBook::print(int index)
{
	std::cout << "First name: " << contacts[index].get_field("first name") << std::endl;
	std::cout << "Last name: " << contacts[index].get_field("last name") << std::endl;
	std::cout << "Nickname: " << contacts[index].get_field("nickname") << std::endl;
	std::cout << "Phone number: " << contacts[index].get_field("phone number") << std::endl;
	std::cout << "Darkest secret: " << contacts[index].get_field("darkest secret") << std::endl;
}

void	PhoneBook::print_list()
{	
	if (contacts[0].get_field("first name").empty())
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
		if (!contacts[i].get_field("first name").empty())
		{
			std::cout << std::setw(10);
			std::cout << i << "|";
			print_cell(contacts[i].get_field("first name"));
			print_cell(contacts[i].get_field("last name"));
			print_cell(contacts[i].get_field("nickname"));	
			std::cout << std::endl;
		}
	}
}

int	PhoneBook::get_index()
{
	int	index;
	int	max;

	max = 0;
	while (max < MAX_CONTACTS && !contacts[max].get_field("first name").empty())
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
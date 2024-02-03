/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:39:21 by bcastelo          #+#    #+#             */
/*   Updated: 2024/02/03 12:15:58 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

public:

static int	Account::getNbAccounts( void )
{
	return (0);
}

static int	Account::getTotalAmount( void )
{
	return (0);	
}

static int	Account::getNbDeposits( void )
{
	return (0);
}

static int	Account::getNbWithdrawals( void )
{
	return (0);
}

static void	Account::displayAccountsInfos( void )
{
	std::cout << "Test" << std::endl;
}

Account::Account( int initial_deposit )
{
	std::cout << "Constructor" << std::endl;
}

Account::~Account( void )
{
	std::cout << "Destructor" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
		std::cout << "Test" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	return (true);
}

int		Account::checkAmount( void ) const;
void	displayStatus( void ) const;

private:
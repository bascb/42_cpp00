/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:39:21 by bcastelo          #+#    #+#             */
/*   Updated: 2024/02/03 21:50:07 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);	
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	static int	index;

	_accountIndex = index++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_nbAccounts++;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
		std::cout << deposit << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > 100)
		return (false);
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (0);
}

void	Account::displayStatus( void ) const
{
	std::cout << "Status" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::cout << "Test" << std::endl;
}

Account::Account( void )
{
	static int	defined;
	
	if (!defined)
	{
	//	_nbAccounts = 0;
	//	_totalAmount = 0;
	//	_totalNbDeposits = 0;
	//	_totalNbWithdrawals = 0;
	defined = 1;
	}
	std::cout << "Constructor Private" << std::endl;
}

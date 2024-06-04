/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:34:59 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/01 01:48:38 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit): _accountIndex(this._nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0){
	this._nbAccounts++;
	this._displayTimestamp();
    std::clog << "index:" << _accounIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(void): _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0){
    std::clog << "Account object created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::clog << "index:" << _accounIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

/*
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;
	の情報を表示する
*/
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout
	<< "accounts:" << this._nbAccounts
	<< ";total:" << this._totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << this._totalNbWithdrawals
	<< std::endl;
}

// 入金
void	Account::makeDeposit( int deposit ){

}

// 出金
bool	Account::makeWithdrawal( int withdrawal ) {

}

// 不要？
// 残高照会
// amountの値を返す
int		Account::checkAmount( void ) const {
	//TODO: ログも出力
	return _amount;
}

// 各メンバの銀行情報
void	Account::displayStatus( void ) const {

}

// 現在日時を表示する
void	_displayTimestamp(void) {
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);

	char buffer[128];
	strftime(buffer, sizeof(buffer), "%Y%m%d_%X", now);

	std::string dateTimeStr(buffer);
	// ':' を削除する
	dateTimeStr.erase(std::remove(dateTimeStr.begin(), dateTimeStr.end(), ':'), dateTimeStr.end());
	std::cout << "[" << dateTimeStr << "] ";
}

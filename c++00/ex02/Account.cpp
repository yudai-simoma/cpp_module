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

Account::Account(int initial_deposit): _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0){
    std::clog << "Account object created" << std::endl;
}

Account::Account(void) {
    std::clog << "Account object created" << std::endl;
}

Account::~Account() {
    std::clog << "Account object destroyed" << std::endl;
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

}

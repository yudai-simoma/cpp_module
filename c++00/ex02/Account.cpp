/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:34:59 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/05 23:27:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(void) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
    std::cout << "Account object created" << std::endl;
}

Account::~Account(void) {
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
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

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

/*
        static int	_nbAccounts;
        static int	_totalAmount;
        static int	_totalNbDeposits;
        static int	_totalNbWithdrawals;
        の情報を表示する
*/
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

// 入金
void Account::makeDeposit(int deposit) {
    int p_amount = this->_amount;

    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
              << ";deposit:" << deposit << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

// 出金
bool Account::makeWithdrawal(int withdrawal) {
    // TODO: リターンせずに規定のログを出力する
    if (this->_amount < withdrawal) {
        this->_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
                  << ";withdrawal:"
                  << "refused" << std::endl;
        return false;
    }

    int p_amount = this->_amount;

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
              << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

// 残高照会
int Account::checkAmount(void) const {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << "amount:" << this->_amount << std::endl;
    return _amount;
}

// 各メンバの銀行情報
void Account::displayStatus(void) const {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

// 現在日時を表示する
void Account::_displayTimestamp(void) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%X", now);

    std::string dateTimeStr(buffer);
    // ':' を削除する
    dateTimeStr.erase(std::remove(dateTimeStr.begin(), dateTimeStr.end(), ':'), dateTimeStr.end());
    std::cout << "[" << dateTimeStr << "] ";
}

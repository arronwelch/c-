/*
 *  TicketMachine.cpp
 *
 *  Created on: 2022-01-14
 *      Author: deft
 */

#include "TicketMachine.h"
#include <iostream>
using namespace std;

TicketMachine::TicketMachine() : PRICE(0)
{
}

TicketMachine::~TicketMachine()
{
}

void TicketMachine::showPrompt()
{
    cout << "something";
}

void TicketMachine::insertMoney(int memory)
{
    balance += memory;
}

void TicketMachine::showBalance()
{
    cout << balance;
}

#include "stdafx.h"
#include "Account.h"




Account::Account()
{
	amount = 0.00;
}

 char Account::getActionCode()
{
	char input;
	cout << "Enter B   show Balance  ..." << endl
		<< "      C   record Check  ..." << endl
		<< "      D   make Deposit  ..." << endl
		<< "      W   Withdrawal    ..." << endl
		<< "      L   List actions  ..." << endl
		<< "      Q   Quit program:   ";

	cin >> input;
	return toupper(input);
}

void Account::displayBalance()
{
	double balance = 0.00;
	char myAction;
	double amount;
	outputData.open("AccountActions.txt");
	if (!(outputData))
	{
		cout << endl;
		cout << "BALANCE of account   $    " << right << setw(10) << balance << endl << endl;
	}

	else
	{
		outputData >> myAction >> amount;
		while (!outputData.eof())
		{

			if ((myAction == 'W') || (myAction == 'C'))
			{
				balance = balance - amount;
			}
			else
			{
				balance = balance + amount;
			}
			outputData >> myAction >> amount;

		}

		cout << "BALANCE of account   $     " << right << setw(10) << balance << endl << endl;

	}
	outputData.close();
}

void Account::recordAction(char something)
{
	double myAmount = getActionAmount(something);
	writeAction(something, myAmount);

}

double Account::getActionAmount(char myAct)
{
	double liri;
	cout << right << getActionLabel(myAct);
	cin >> liri;
	cout << endl << endl;
	return liri;
}


string Account::getActionLabel(char move)
{
	if (move == 'C')
	{

		return "Amount of check       $   ";
	}

	else if (move == 'W')
	{

		return "Amount of withdrawal  $   ";
	}

	else
	{

		return "Amount of  deposit    $   ";
	}

}

void Account::writeAction(char myChar, double myMoney)
{
	outputData.open("AccountActions.txt", ios::app);
	outputData << myChar << right << setw(10) << myMoney << endl;
	outputData.close();
}

void Account::listActions()
{

	double amount = 0.00;
	char myAction;
	double balance = 0.00;
	outputData.open("AccountActions.txt");
	if (!(outputData))
	{
		cout << "Action file not found. Make an initial deposit" << endl;
		cout << "BALANCE of account   $    " << right << setw(10) << balance << endl << endl;
	}

	else
	{

		outputData >> myAction >> amount;

		while (!outputData.eof())
		{

			if (myAction == 'W')
			{
				cout << "withdrawal          -     " << right << setw(10) << amount << endl << endl;
				balance = balance - amount;
			}

			else if (myAction == 'C')
			{
				cout << "check               -     " << right << setw(10) << amount << endl << endl;
				balance -= amount;
			}
			else
			{
				cout << "deposit             +     " << right << setw(10) << amount << endl << endl;
				balance = balance + amount;
			}

			outputData >> myAction >> amount;

		}

		cout << "BALANCE of account   $    " << right << setw(10) << balance << endl << endl;

	}
	outputData.close();
}




// AccountManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Account.h"
#include <fstream>
#include <cctype>
#include <string>

using namespace std;



int main()
{
	Account myAccount;
    char actionCode;
	double balance = 0.00;
	cout << fixed << setprecision(2);
	actionCode = myAccount.getActionCode();
	while (actionCode != 'Q')
	{
		switch (actionCode)
		{
		case 'B':
			myAccount.displayBalance(); //show balance
			break;
		case 'C':
			myAccount.recordAction('C');
			break;
		case 'D':
			myAccount.recordAction('D');
			break;
		case 'W':
			myAccount.recordAction('W');
			break;
		case 'L':
			myAccount.listActions();
			break;

		}
		actionCode = myAccount.getActionCode();
	}

	cout << endl;
	system("pause");
	return 0;
}


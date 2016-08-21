#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <string>


using namespace std;

class Account
{
private:
	double amount;
	fstream outputData;
	
public:
	Account();
	char getActionCode();
	void displayBalance();
	void recordAction(char);
	double getActionAmount(char);
	void writeAction(char, double);
	void listActions();
	string getActionLabel(char);
	
};


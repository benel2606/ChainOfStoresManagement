/*
Assignment: 4
Campus: Ashdod
Author: Benel Aharon
ID: 307908111
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Chain.h"
#include "Store.h"
#include "Food.h"
using namespace std;


void Food::print_chain() const
{
	cout << "***"<< chain_name<<"***"<<endl;
	if (size)
	{
		cout << "Stores information: " << endl;
		cout << "-------------------" << endl;
		for (int i = 0; i < size; i++)
			chain[i]->print_store();
	}
	else cout << "There are no stores!" << endl;
	cout << "Provider number: " << provider_num << endl;
}

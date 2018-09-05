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
using namespace std;

#pragma once

class Clouths :public Chain
{
private:
	string provider;
public:
	Clouths() { provider = 'A'; };
	Clouths(string c_name, string p_name) :Chain(c_name) { provider = p_name; }     // Chain constractor with provider
	virtual void print_chain()const;                                                // Virtual function to print food chaim
};


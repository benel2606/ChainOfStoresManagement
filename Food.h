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

class Food: public Chain
{
private:
	int provider_num;
public:
	Food() { provider_num = 0; }
	Food(string c_name, int p_num):Chain(c_name) { provider_num = p_num; }             // Chain constractor with provider number
	virtual void print_chain()const;                                                   // Virtual function to print food chain
};
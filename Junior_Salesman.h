/*
Assignment: 4
Campus: Ashdod
Author: Benel Aharon
ID: 307908111
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Workers.h"
using namespace std;

#pragma once
class Junior_Salesman :public Workers
{
protected:
	float* sale_sum;
	int sales_num;
public:
	Junior_Salesman() { this->sale_sum = NULL; this->sales_num = 0; }
	Junior_Salesman(string n, long num, float job, float salary) :Workers(n, num, job, salary) {}
	Junior_Salesman(Junior_Salesman const &j_s) { this->sale_sum = j_s.sale_sum; }
	~Junior_Salesman() { delete[]sale_sum; }
	virtual void print()const;
	virtual int get_sales_num()const { return sales_num; }
	virtual float get_sales_array(int i)const { return sale_sum[i]; }
	virtual void sale(float sale);                                             // virtual function to add sale in Senior/Junior salesman
	virtual bool checkSale(float val)const;                                    // check in sales array if the value existent
	float average()const;                                                      // calculate average
	virtual void print_sales()const;                                           // print sales array
	virtual double salary()const { return ((Junior_Salesman::sales_num) + (Junior_Salesman::average()) + (Junior_Salesman::basic_salary))*(Junior_Salesman::job_percent); }
};


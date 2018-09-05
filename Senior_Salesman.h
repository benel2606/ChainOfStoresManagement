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
#include "Junior_salesman.h"
using namespace std;

#pragma once
class Senior_Salesman :public Junior_Salesman
{
private:
	float* cancelation;
	int cancel_num;
public:
	Senior_Salesman() { this->cancelation = NULL; this->cancel_num=0; }             //defult constractor
	Senior_Salesman(string n, long num, float job, float salary) :Junior_Salesman(n, num, job, salary) {}
	Senior_Salesman(Senior_Salesman const &s_s) { this->cancelation = s_s.cancelation; }
	~Senior_Salesman() { delete[]cancelation; }
	virtual void print()const;
	int get_delete_num()const { return cancel_num; }             
	void cancel(float cancel);                                                      // Add cancelation 
	virtual double salary()const {return 1.5*(((Junior_Salesman::sales_num) + (Junior_Salesman::average()) + (Junior_Salesman::basic_salary))*(Junior_Salesman::job_percent));}
	
};
/*
Assignment: 4
Campus: Ashdod
Author: Benel Aharon
ID: 307908111
*/
#include <iostream>
#include <string>
using namespace std;
#include "Workers.h"
#pragma once

class Store
{
private:
	string chain_name;
	int store_id;
	Workers **workers;
	int size;

public: 
	Store() { store_id = 0; workers= NULL; this->size = 0; }
	Store(string chain_name,int id) { this->chain_name = chain_name; this->store_id = id; }
	~Store() { for (int i = 0; i < size; i++) delete[]workers[i]; delete[] workers; }
	void add_worker(string name, long id, float job_per, float salary,int level,char type);
	void print_employee(long emp_id)const;
	void add_value(float value,long emp_id);                                   // Add value to sales array
	void add_cancel(int emp_id, float value);                                  // Add value to cancelation array
	void add_action_cashier();                                                 // Add action to cashier
	bool check_id(long id)const;                                               // check if the id existent
	int get_store_id()const { return store_id ;}
	int get_size()const { return size; }
	double sum_salaries_store()const;                                          // calculate the sum of workers salary in store
	void print_store()const;                                                   // print information of store
	
};
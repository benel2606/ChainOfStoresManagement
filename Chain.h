/*
Assignment: 4
Campus: Ashdod
Author: Benel Aharon
ID: 307908111
*/
#include <iostream>
#include <string>
#include "Store.h"
using namespace std;

#pragma once
class Chain
{
protected:
	Store** chain;
	string chain_name;
	int size;

public:
	Chain() { chain = NULL; this->chain_name = 'a'; this->size = 0; }
	Chain(string chain_name) { this->chain_name = chain_name; }
	~Chain() { for (int i = 0; i < size; i++) delete[]chain[i]; delete[]chain; }
	virtual void print_chain()const = 0;
	Store* get_store(int store_id);
	bool check_store_id(int store_id)const;                                         // Check if the store existent 
	bool check_worker_id(long emp_id)const;
	void add_store(int store_id);                                                   // Add store to store array
	void add_value_to_store(int store_id, long emp_id, float value);                // Add sales to store 
	void add_cancel(long emp_id, int shop_id, float value);                         // Add cancelation to store
	void add_employee(string name, long id, char type, float job_per, float salary, string chain_name, int Store_id, int level);  // Add employee to store
	void print_employee(long emp_id)const;                                          // Print employee
	double sum_salaries_chain()const;                                               // Sum workers salaries of chain


	
};

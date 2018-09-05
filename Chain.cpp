/*
Assignment: 4
Campus: Ashdod
Author: Benel Aharon
ID: 307908111
*/
#include <iostream>
#include <string>
#include "Chain.h"
#include "Branch_Manager.h"
#include "Senior_Salesman.h"
#include "Junior_Salesman.h"
#include "Cashier.h"
#include "Store.h"
using namespace std;

Store* Chain::get_store(int store_id)
{
	for (int i = 0; i < size; i++)
	{
		if (chain[i]->get_store_id() == store_id)
			return chain[i];
	}
	exit(0);
}
bool Chain::check_store_id(int store_id) const
{
	for (int i = 0; i < size; i++)
		if (chain[i]->get_store_id() == store_id)
			return false;                                                      // Return false if the store exists 
	return true;                                                               // Return false if the store not exists
}
bool Chain::check_worker_id(long emp_id) const
{
	for (int i=0;i<size;i++)
		if (!(chain[i]->check_id(emp_id)))
				return false;
	return true;
}
void Chain::add_store(int store_id)
{
	int flag = 0;
	if (check_store_id(store_id))                                              // Check if the store exist
	{
		for (int i = 0; i < size; i++)
		{
			if (chain[i]->get_store_id() == store_id)
				flag = 1;
		}
		if (!flag)
		{
			Store **tmp = NULL;
			if (!size)                                                         // If store array is 'NULL'
			{
				chain = new Store*[size];
				chain[size] = new Store(chain_name, store_id);
				size++;
			}
			else
			{
				tmp = new Store*[size + 1];                                    // using with tmp array to set new store
				for (int i = 0; i < size; i++)
					tmp[i] = chain[i];

				tmp[size] = new Store(chain_name, store_id);

				chain = new Store*[size + 1];
				for (int i = 0; i < size + 1; i++)
					chain[i] = tmp[i];
				size++;

				delete[]tmp;
			}
		}
		cout << "Add store successfully!" << endl;
	}
	else cout << "The store already exist." << endl;
}
void Chain::add_value_to_store(int store_id, long emp_id, float value)
{
	for (int i = 0; i < size; i++)
	{
		if (chain[i]->get_store_id() == store_id)
		{
			chain[i]->add_value(value, emp_id);
		}

	}
}
void Chain::add_cancel(long emp_id, int shop_id, float value)
{
	for (int i = 0; i < size; i++)
	{
		if (chain[i]->get_store_id() == shop_id)
			chain[i]->add_cancel(emp_id, value);
	}
}
void Chain::add_employee(string name, long id, char type, float job_per, float salary, string chain_name, int Store_id, int level)
{
	int flag = 0;
	if (check_worker_id(id))
	{
		for (int i = 0; i < size; i++)
		{
			if (chain[i]->get_store_id() == Store_id)
			{
				flag = 1;
					chain[i]->add_worker(name, id, job_per, salary, level, type);
					cout << "Add employee successfully!" << endl;
			}
		}
		if (!flag)
			cout << "ERROR-Received store not exists." << endl;
	}
	else 
		cout << "ERROR-Received ID already exists." << endl;
}
void Chain::print_employee(long emp_id) const
{
	for (int i = 0; i < size; i++)
		chain[i]->print_employee(emp_id);
}
double Chain::sum_salaries_chain()const
{
double sum_salaries=0;
for (int i = 0; i < size; i++)
	sum_salaries += chain[i]->sum_salaries_store();

return sum_salaries;
}

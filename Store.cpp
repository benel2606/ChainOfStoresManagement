/*
Assignment: 4
Campus: Ashdod
Author: Benel Aharon
ID: 307908111
*/
#include <iostream>
#include <string>
#include "Branch_Manager.h"
#include "Senior_Salesman.h"
#include "Junior_Salesman.h"
#include "Cashier.h"
#include "Store.h"
using namespace std;

void Store::add_worker(string name, long id, float job_per, float salary,int level, char type)
{
	int level_man = 1;
	Workers **tmp = NULL;
	if (type == 'A')
	{
		cout << "Enter a level of management (1-3): ";                         // Check management level to branch manager
		cin >> level_man;
		cout << endl;
		if (!size)
		{
			workers = new Workers*[1];
			workers[0] = new Branch_Manager(name, id, job_per, salary, level_man);
			size++;
		}
		else
		{
			tmp = new Workers*[size+1];
			for (int i = 0; i < size; i++)
				tmp[i] = workers[i];

			tmp[size] = new Branch_Manager(name, id, job_per, salary, level_man);
			delete[]workers;
			workers = new Workers*[size + 1];
			for (int i = 0; i < size + 1; i++)
				workers[i] = tmp[i];
			size++;

			delete[]tmp;
		}
	}
	if (type == 'B')
	{
		if (!size)
		{
			workers = new Workers*[1];
			workers[0] = new Senior_Salesman(name, id, job_per, salary);
			size++;
		}
		else
		{
			tmp = new Workers*[size + 1];
			for (int i = 0; i < size; i++)
				tmp[i] = workers[i];

			tmp[size] = new Senior_Salesman(name, id, job_per, salary);
			delete[]workers;
			workers = new Workers*[size + 1];
			for (int i = 0; i < size + 1; i++)
				workers[i] = tmp[i];
			size++;

			delete[]tmp;
		}
	}
	if (type == 'C')
	{
		if (!size)
		{
			workers = new Workers*[1];
			workers[0] = new Junior_Salesman(name, id, job_per, salary);
			size++;
		}
		else
		{
			tmp = new Workers*[size + 1];
			for (int i = 0; i < size; i++)
				tmp[i] = workers[i];

			tmp[size] = new Junior_Salesman(name, id, job_per, salary);
			delete[]workers;
			workers = new Workers*[size + 1];
			for (int i = 0; i < size + 1; i++)
				workers[i] = tmp[i];
			size++;

			delete[]tmp;
		}
	}
	if (type == 'D')
	{
		if (!size)
		{
			workers = new Workers*[1];
			workers[0] = new Cashier(name, id, job_per, salary);
			size++;
		}
		else
		{
			tmp = new Workers*[size + 1];
			for (int i = 0; i < size; i++)
				tmp[i] = workers[i];

			tmp[size] = new Cashier(name, id, job_per, salary);
			delete[]workers;
			workers = new Workers*[size + 1];
			for (int i = 0; i < size + 1; i++)
				workers[i] = tmp[i];
			size++;

			delete[]tmp;
		}
	}
}
void Store::print_employee(long emp_id) const
{
	for (int i = 0; i < size; i++)
		if (workers[i]->get_worker_id() == emp_id)
		{
			workers[i]->print();
			cout << endl << "Salary: " << workers[i]->salary() << endl;
		}
}
void Store::add_value(float value, long emp_id)
{
	int flag = 0;
	for (int i = 0; i < size; i++)
	{
		if (workers[i]->get_worker_id() == emp_id)                             // Check if the ID exist
		{
			if (typeid (*workers[i]) == typeid(Senior_Salesman))
			{
				dynamic_cast<Senior_Salesman*>(workers[i])->sale(value);
				flag = 1;
				cout << "Add successfully" << endl;
			}
			if (typeid (*workers[i]) == typeid(Junior_Salesman))
			{
				dynamic_cast<Junior_Salesman*>(workers[i])->sale(value);
				flag = 1;
				cout << "Add successfully" << endl;
			}
		}
	}
		if (flag)
		{
			for (int i = 0; i < size; i++)
			{
				if (typeid (*workers[i]) == typeid(Cashier))
				{
					dynamic_cast<Cashier*>(workers[i])->set_action();
				}
			}
		}
		else
			cout << "ERROR-The ID doesn't exist or the worker is not a salesman" << endl;
}
void Store::add_cancel(int emp_id, float value)
{
	int flag1 = 0, flag2 = 0, flag3 = 0;

	for (int i = 0; i < size; i++)                                             // Check if the worker is a senior or junior to check if the recived value exist
	{
		if (typeid(*workers[i]) == typeid(Senior_Salesman) || typeid(*workers[i]) == typeid(Junior_Salesman))
		{
			if (dynamic_cast<Junior_Salesman*>(workers[i])->checkSale(value) == true)
				flag2 = 1;
		}
	}
	if (flag2)
	{
		for (int i = 0; i < size; i++)
		{
			if (workers[i]->get_worker_id() == emp_id)                         // Check if the ID exist
			{
				if (typeid (*workers[i]) == typeid(Senior_Salesman))           
				{
					flag1 = 1;
					dynamic_cast<Senior_Salesman*>(workers[i])->cancel(value);
				}
			}
		}
	}
	else cout << "ERROR-The sale value is not exist in store or the salesman is not senior salesman" << endl;
	if (flag1)
	{
		for (int i = 0; i < size; i++)                                         // Add action to Cashier
		{
			if (typeid (*workers[i]) == typeid(Cashier))
			{
				flag1 = 1;
				dynamic_cast<Cashier*>(workers[i])->set_action();
			}
		}
	}
}
void Store::add_action_cashier()
{
	for (int i = 0; i < size; i++)
	{
			if (typeid (*workers[i]) == typeid(Cashier))
				dynamic_cast<Cashier*>(workers[i])->set_action();
	}
}
bool Store::check_id(long id) const
{
	for (int i = 0; i < size; i++)
		if (workers[i]->get_worker_id() == id)
			return false;
	return true;
}
double Store::sum_salaries_store()const
{
	double sum_salaries = 0;

	for (int i = 0; i < size; i++)
		sum_salaries += workers[i]->salary();

	return sum_salaries;
}
void  Store::print_store()const
{
	cout << "Store ID: " <<"( "<< store_id <<" )"<< endl;
	cout << "Employee names: " << endl;
	cout << "---------------" << endl;
	if (!workers) cout << "There are no employees in the store " << endl;
	for (int i = 0; i < size; i++)
	{
		workers[i]->print();
		cout <<endl<<"Salary: "<<workers[i]->salary() << endl;
		cout << "***********************" << endl;
	}
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}

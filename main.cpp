/*
Assignment: 4
Campus: Ashdod
Author: Benel Aharon
ID: 307908111
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Branch_Manager.h"
#include "Senior_Salesman.h"
#include "Junior_Salesman.h"
#include "Cashier.h"
#include "Store.h"
#include "Chain.h"
#include "Food.h"
#include "Cloths.h"
using namespace std;

int main()
{
	int op = 0, shop_id, emp_id,level=1;
	string chain_name, emp_name;
	char type;
	float salary, job_per,value;

	//init-----------------------------------------------------------------------------------------

	Chain **chain = new Chain*[3];
		
	chain[0] = new Clouths("Golbary", "Moshe Gabay");
	chain[1] = new Food("Super Sal",4);
	chain[1]->add_store(3);
	chain[1]->add_store(81);
	chain[2] = new Clouths("TNT", "Ruti Sulemani");
	chain[2]->add_store(3);
	//---------------------------------------------------------------------------------------------
	while (op != 10)
	{
		system("cls");
		cout << "1- Add Shop" << endl;
		cout << "2- Add Employee" << endl;
		cout << "3- Shopping" << endl;
		cout << "4- Return Item" << endl;
		cout << "5- Print Chain" << endl;
		cout << "6- Sum Salaries Chain" << endl;
		cout << "7- Sum Salaries Shop" << endl;
		cout << "8- Print Shop" << endl;
		cout << "9- Print Employee" << endl;
		cout << "10- Exit" << endl << endl;
		cout << "Please enter your choise: ";
		cin >> op;
		switch (op)
		{
		case 1:                                                                // Add Shop
			system("cls");
			cout << "Enter the following fields to add store:" << endl;
			cout << "Chain name: ";
			getchar();
			getline (cin,chain_name);
			cout << "Shop id: ";
			cin >> shop_id;
			if (chain_name == "Golbary")
				chain[0]->add_store(shop_id);
			if (chain_name == "Super Sal")
				chain[1]->add_store(shop_id);
			if (chain_name == "TNT")
				chain[2]->add_store(shop_id);
			getchar();
			getchar();
			break;

		case 2:                                                                // Add Employee
			system("cls");
			cout << "Enter the following fields to add employee:" << endl;
			cout << "Name: ";
			getchar();
			getline (cin, emp_name);
			cout << "ID: ";
			cin >> emp_id;
			cout << "Type: ";
			cin >> type;
			cout << "Job precent: ";
			cin >> job_per;
			cout << "Salary: ";
			cin >> salary;
			cout << "Chain name: ";
			getchar();
			getline(cin, chain_name);
			cout << "Shop id: ";
			cin >> shop_id;

			if (chain_name == "Golbary")
				chain[0]->add_employee(emp_name, emp_id, type, job_per, salary, chain_name, shop_id, level);
			if (chain_name == "Super Sal")
				chain[1]->add_employee(emp_name, emp_id, type, job_per, salary, chain_name, shop_id, level);
			if (chain_name == "TNT")
				chain[2]->add_employee(emp_name, emp_id, type, job_per, salary, chain_name, shop_id, level);
			getchar();
			getchar();
			break;

		case 3:                                                                // Shopping
			system("cls");
			cout << "Enter the following fields to add shopping:" << endl;
			cout << "Shop id: " ;
			cin >> shop_id;
			cout << "Chain name: ";
			getchar();
			getline(cin, chain_name);
			cout << "Value: " ;
			cin >> value;
			cout << "Employee id: ";
			cin >> emp_id;
			
			if (chain_name == "Golbary")
				chain[0]->add_value_to_store(shop_id,emp_id,value);
			if (chain_name == "Super Sal")
				chain[1]->add_value_to_store(shop_id, emp_id, value);
			if (chain_name == "TNT")
				chain[2]->add_value_to_store(shop_id, emp_id, value);
			getchar();
			getchar();
			break;
		case 4:                                                                // Return Item
			system("cls");
			cout << "Enter the following fields to add canceltion:" << endl;
			cout << "Shop id: ";
			cin >> shop_id;
			cout << "Chain name: ";
			getchar();
			getline(cin, chain_name);
			cout << "Value: ";
			cin >> value;
			cout << "Employee id: ";
			cin >> emp_id;

			if (chain_name == "Golbary")
				chain[0]->add_cancel(emp_id, shop_id, value);
			if (chain_name == "Super Sal")
				chain[1]->add_cancel(emp_id, shop_id, value);
			if (chain_name == "TNT")
				chain[2]->add_cancel(emp_id, shop_id, value);
			getchar();
			getchar();
			break;

		case 5:                                                                // Print Chain
			system("cls");
			cout << "Enter the following fields to print chain informtion:" << endl;
			cout << "Chain name: ";
			getchar();
			getline(cin, chain_name);
			if (chain_name == "Golbary")
				chain[0]->print_chain();
			if (chain_name == "Super Sal")
				chain[1]->print_chain();
			if (chain_name == "TNT")
				chain[2]->print_chain();
			getchar();
			break;

		case 6:                                                                // Sum Salaries Chain
			system("cls");
			cout << "Enter the following fields to calulate and print the sum of worker salaries in chain:" << endl;
			cout << "Chain name: ";
			getchar();
			getline(cin, chain_name);
			if (chain_name == "Golbary")
				cout<<"The sum of workers salaries in 'Golbary' chain:"<<chain[0]->sum_salaries_chain()<<endl;
			if (chain_name == "Super Sal")
				cout << "The sum of workers salaries in 'SuperSal' chain:" << chain[1]->sum_salaries_chain()<<endl;
			if (chain_name == "TNT")
				cout << "The sum of workers salaries in 'TNT' chain:" << chain[2]->sum_salaries_chain()<<endl;
			getchar();
			break;

		case 7:                                                                // Sum Salaries shop
			system("cls");
			cout << "Enter the following fields to calulate and print the sum of worker salaries in store:" << endl;
			cout << "Shop id: ";
			cin >> shop_id;
			cout<<	"Chain name: ";
			getchar();
			getline(cin, chain_name);
			if (chain_name == "Golbary")
				cout << "The sum of workers salaries in 'Golbary' chain, shop number " << shop_id << " is: " << chain[0]->get_store(shop_id)->sum_salaries_store()<<endl;
			if (chain_name == "Super Sal")
				cout << "The sum of workers salaries in 'SuperSal' chain, shop number " << shop_id << " is: " << chain[1]->get_store(shop_id)->sum_salaries_store()<<endl;
			if (chain_name == "TNT")
				cout << "The sum of workers salaries in 'TNT' chain, shop number " << shop_id << " is: " << chain[2]->get_store(shop_id)->sum_salaries_store()<<endl;
			getchar();
			break;
			
		case 8:                                                                // Print Shop
			system("cls");
			cout << "Enter the following fields to calulate and print info store:" << endl;
			cout << "Shop id: ";
			cin >> shop_id;
			cout << "Chain name: ";
			getchar();
			getline(cin, chain_name);

			if (chain_name == "Golbary")
				 chain[0]->get_store(shop_id)->print_store();
			if (chain_name == "Super Sal")
				chain[1]->get_store(shop_id)->print_store();
			if (chain_name == "TNT")
				chain[2]->get_store(shop_id)->print_store();
			getchar();
			break;

		case 9:                                                                // Print employee
			system("cls");
			cout << "Enter the following fields to calulate and print info employee:" << endl;
			cout << "employee id: ";
			cin >> emp_id;
			cout<<	"chain name: ";
			getchar();
			getline(cin, chain_name);
			if (chain_name == "Golbary")
				chain[0]->print_employee(emp_id);
			if (chain_name == "Super Sal")
				chain[1]->print_employee(emp_id);
			if (chain_name == "TNT")
				chain[2]->print_employee(emp_id);
			getchar();
			break;

		case 10:                                                               // Exit
			system("cls");
			cout << "Have a nice day!" << endl;
			break;

		}

	}
	system("pause");
	return 0;

}
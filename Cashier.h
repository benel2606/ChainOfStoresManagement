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
class Cashier:public Workers
{
private:
	int action;
public:
	Cashier() { this->action = 0; }
	Cashier(string n, long num, float job, float salary) :Workers(n, num, job, salary) { this->action = 0; }
	Cashier(Cashier const &c) { this->action = c.action; }
	virtual void print() const { cout << "<Cashier>" << endl; cout << "Name: " << name << endl << "ID: " << id << endl << "Job percent: " << job_percent * 100 << endl << "Basic salary: " << basic_salary << endl; cout << "Action:" << action << endl; }
	void set_action() {this->action++;}                                           // Set action to 'action' variable 
	int get_action()const { return action; }             
	virtual double salary()const { return (this->action + (Cashier::basic_salary))*(Cashier::job_percent); } 

};

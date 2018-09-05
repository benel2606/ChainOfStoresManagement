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
class Branch_Manager :public Workers
{
private:
	int manager_level;
public:
	Branch_Manager() { manager_level = 1; }                     //defult constractor
	Branch_Manager(string n, long num, float job, float salary ,int level) : Workers(n, num, job, salary) { manager_level = level; }
	virtual double salary()const { return (Workers::basic_salary)*(Workers::job_percent)*manager_level; } 
	virtual void print()const { cout << "Level: " << manager_level << endl; cout << "name: " << name << endl << "ID: " << id << endl << "job percent: " << job_percent * 100 << endl << "basic salary: " << basic_salary << endl; }
};

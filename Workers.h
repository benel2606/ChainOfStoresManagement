/*
Assignment: 4
Campus: Ashdod
Author: Benel Aharon 
ID: 307908111
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

#pragma once
class Workers
{
protected:
	 string name;
	 long id;
	 float job_percent;
	 float basic_salary;
public:
	Workers() { name = '/'; id = 1; job_percent = 0.0; basic_salary = 0.0; }   //defult constractor
	Workers(string n, long num, float job, float salary) { name = n; id = num; job_percent = job/100; basic_salary = salary; }
	Workers(const Workers &w) { name = w.name; id = w.id; job_percent = w.job_percent; basic_salary = w.basic_salary; }
	virtual int get_worker_id() { return id; }
	virtual ~Workers()=0{};                                                    // abstract destructor
	virtual void print()const = 0;                                             // abstract function to print workers
	virtual double salary()const=0;                                            // abstract function to calculate salary

};


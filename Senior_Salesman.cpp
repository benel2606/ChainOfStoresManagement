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
#include "Senior_Salesman.h"
using namespace std;

void Senior_Salesman::print() const
{
	cout << "<Senior_Salesman>" << endl;
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Job_percent: " << job_percent * 100 << endl;
	cout << "Basic salary: " << basic_salary << endl;
	cout << "Sales: " << endl;
	if (!sale_sum)
		cout << "There are no sales!"<<endl;
	else
	{
		for (int i = 0; i < sales_num; i++)
			cout << sale_sum[i] << endl;
	}
	cout << "Cancelation: " << endl;
	if (!cancelation)
		cout << "There are no cancelation!" << endl;
	else
	{
		for (int i = 0; i < cancel_num; i++)
			cout << cancelation[i] << endl;
	}
}
void Senior_Salesman::cancel(float cancel)
{
	int count_cancel = 0;
	float* temp;

	if (!cancelation)                                           // If the array is empty
	{
		cancelation = new float[1];
		cancelation[0] = cancel;
		cancel_num++;
	}
	else
	{
		for (int i = 0; cancelation[i] != NULL; i++)            // Count the cancel number in array
			count_cancel++;

		temp = new float[count_cancel];

		for (int i = 0; i < count_cancel; i++)                  // Copy the array to temp array
			temp[i] = cancelation[i];

		delete[]cancelation;                                    // Delete array
		cancelation = new float[count_cancel + 1];              // Set array with new size
		cancelation[0] = cancel;                                // Add the new cancel to array

		for (int i = 1; i < count_cancel; i++)                  // Return the previous cancel 
			cancelation[i] = temp[i - 1];

		delete[]temp;										    //Delete temp array
		cancel_num++;
	}
}

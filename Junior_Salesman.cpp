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
#include "Junior_Salesman.h"
#include "Cashier.h"
using namespace std;

void Junior_Salesman::print() const
{
	cout << "<Junior_Salesman>" << endl;
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
}
void Junior_Salesman::sale(float sale)
{
	int count_sale = 0;
	float* temp;

	if (!sale_sum)                                              // If the array is empty
	{
		sale_sum = new float[1];
		sale_sum[0] = sale;
		sales_num++;                                            // Increase the number of sales          
	}
	else
	{
		for (int i = 0; sale_sum[i] != NULL; i++)               // Count the sales number in array
			count_sale++;
		temp = new float[count_sale];

		for (int i = 0; i < count_sale; i++)                    // Copy the array to temp array
			temp[i] = sale_sum[i];

		delete[]sale_sum;                                       // Delete array
		sale_sum = new float[count_sale + 1];                   // Set array with new size
		sale_sum[0] = sale;                                     // Add the new sale to array

		for (int i = 1; i < count_sale; i++)                    // return the previous sales 
			sale_sum[i] = temp[i - 1];

		delete[]temp;										    //delete tmp array

		sales_num++;                                            //Increase the number of sales
	}
}
bool Junior_Salesman::checkSale(float val)const
{
	for (int i = 0; i < sales_num; i++)
		if (sale_sum[i] == val)
			return true;
	return false;
}
float Junior_Salesman::average()const
{
	float average = 0;
	if (sales_num)
	{
		for (int i = 0; i < sales_num; i++)
			average += sale_sum[i];

		average /= sales_num;
	}
	else
		average = 0;
	
	
	return average;
}
void Junior_Salesman::print_sales() const
{
	if (sales_num)
	{
		cout << "The shopping of salesman are: " << endl;
		for (int i = 0; i < sales_num; i++)
			cout << "- " << sale_sum[i]<<endl;
	}
}


//#include "stdafx.h"
#include "conio.h"
#include "iostream"
#include "stdlib.h"
#include "locale.h"
using namespace std;
int main(){

	int n, i, j, sum = 0;
	int serv[10], wait[10], obr[10], v = 2;
	double avewait = 0.0, aveobr = 0.0;
	setlocale(LC_ALL, "russian");
	
	cout << "Задан фиксированный квант времени v=2 \n";
	cout << "Введите кол-во процессов: " << endl;
	cin >> n;


	for (i = 0; i<n; i++)
	{
		cout << "Введите время обслуживания: \n";
		cin >> serv[i];
	}
	system("CLS");

	for (i = 0; i<n; i++)
	{
		sum = 0;
		for (j = 0; j<i; j++)
			sum = sum + serv[j];
		wait[i] = sum;
	}

	for (i = 0; i<n; i++)
	{
		obr[i] = wait[i] + serv[i];

	}
	for (i = 0; i<n; i++)
	{
		avewait += wait[i];
		aveobr += obr[i];
	}

	avewait /= n;
	aveobr /= n;
	cout << "\n";
	cout << "Процесс      Обслуживание       Ожидание       Выполнение ";
	cout << "\n\n";

	for (i = 0; i<n; i++)
	{
		cout << i + 1 << "\t\t" << serv[i] << "\t\t" << wait[i] << "\t\t" << obr[i];
		printf("\n");
	}
	cout << "=====================================================================\n\n";
	printf("Среднее время ожидания = %.2f", avewait);
	printf("\n");
	printf("Среднее время выполнения = %.2f", aveobr);
	_getch();
}

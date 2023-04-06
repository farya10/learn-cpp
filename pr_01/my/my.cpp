// var_3 
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char name[20];
	char manufacturer[20];
	unsigned short number;
	float price;
	struct Date date[3];

};

void PrintDate(unsigned short day, unsigned short month, unsigned short year)
{
	cout << "|";

	if (day > 9) { cout.width(2); cout << left << day << left << "."; }
	else { cout.width(1); cout << left << "0"; cout.width(1); cout << left << day << left << "."; }

	if (month > 9) { cout.width(2); cout.fill(' '); cout << left << month << left << "."; }
	else { cout.width(1); cout << left << "0"; cout.width(1); cout << left << month << left << "."; }

	cout.width(4); cout << left << year; cout.width(6); cout << right << "|" << endl;
}


void PrintTable(struct Record* records)
{
	cout << "-";  cout.width(80); cout.fill('-'); cout << "-" << endl;

	cout.fill(' '); cout.width(80); cout << left << "|Офисные пакеты"; cout << '|' << endl;
	cout.width(80); cout.fill('-'); cout << "|"; cout << "|" << endl;
	cout.fill(' ');

	cout.width(16); cout << "|Наименование";
	cout.width(16); cout << "|Производитель";
	cout.width(16); cout << "|Кол-во сост. ч.";
	cout.width(16); cout << "|Цена ($)";
	cout.width(16); cout << "|Дата релиза";
	cout << '|' << endl;

	cout.width(80); cout.fill('-'); cout << left << "|"; cout << left << "|" << endl;

	cout.fill(' ');


	for (int i = 0; i < 3; i++)
	{
		cout << "|"; cout.width(15); cout << records[i].name;
		cout << "|"; cout.width(15); cout << records[i].manufacturer;
		cout << "|"; cout.width(15); cout << records[i].number;
		cout << "|"; cout.width(15); cout << records[i].price;
		PrintDate(records[i].date->day, records[i].date->month, records[i].date->year);

		cout.width(80); cout.fill('-'); cout << left << "|"; cout << left << "|" << endl;

		cout.fill(' ');
	}

	cout.fill(' '); cout.width(80); cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet"; cout << '|' << endl;

	cout << "-";  cout.width(80); cout.fill('-'); cout << "-" << endl;
}

/*void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}*/

void MinMax(struct Record* records)
{
	unsigned short min, max, nmin, nmax;

	min = max = records[0].date->month;
	nmin = nmax = 0;

	for (int i = 1; i < 3; i++)
	{
		if (records[i].date->month < min)
		{
			min = records[i].date->month;
			nmin = i;
		};

		if (records[i].date->month > max)
		{
			max = records[i].date->month;
			nmax = i;
		};
	};

	struct Record bufer = records[nmin];
	records[nmin] = records[nmax];
	records[nmax] = bufer;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[3] = {
	{ "Office", "Microsoft", 4, 870.99, {11,01,2011} },
	{ "SmartSute", "Lotus", 5, 1020.99, {21,12,2012} },
	{ "StarOffice", "Sun", 4, 9.99, {21,10,2020} },
	};


	MinMax(records);

	PrintTable(records);

}
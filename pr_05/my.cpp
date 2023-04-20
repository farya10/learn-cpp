#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>

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
	struct Date date;

};

class clDate
{
private:
	unsigned short year;
	unsigned short month;
	unsigned short day;
public:

	char delimiter = '.';

	clDate()
	{

		setDate(2, 2, 1920);
	}

	clDate(unsigned short _day, unsigned short _month, unsigned short _year)
	{
		setDate(_day, _month, _year);
	}

	Date getDate()
	{
		struct Date MD;
		MD.year = year;
		MD.month = month;
		MD.day = day;
	}

	void setDate(Date _mD)
	{
		setDate(_mD.day, _mD.month, _mD.year);
	}
	void setDate(unsigned short _day, unsigned short _month, unsigned short _year)
	{
		this->day = _day;
		this->month = _month;
		this->year = _year;
	}

	void printDate() {
		if (this->day > 0 and this->day < 10)
			cout << "0";
		cout << day << this->delimiter;
		if (this->month > 0 and this->month < 10)
			cout << "0";
		cout << month << this->delimiter << year << endl;
	}
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
		PrintDate(records[i].date.day, records[i].date.month, records[i].date.year);

		cout.width(80); cout.fill('-'); cout << left << "|"; cout << left << "|" << endl;

		cout.fill(' ');
	}

	cout.fill(' '); cout.width(80); cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet"; cout << '|' << endl;

	cout << "-";  cout.width(80); cout.fill('-'); cout << "-" << endl;
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

	class clDate date1;
	date1.printDate();
}


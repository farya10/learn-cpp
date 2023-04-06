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
	struct Date date;

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


struct node {
	Record data;
	struct node* next;
};

struct node* myHead;
int countItem = 0;



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


void MinMax(struct Record* records)
{
	unsigned short min, max, nmin, nmax;

	min = max = records[0].date.month;
	nmin = nmax = 0;

	for (int i = 1; i < 3; i++)
	{
		if (records[i].date.month < min)
		{
			min = records[i].date.month;
			nmin = i;
		};

		if (records[i].date.month > max)
		{
			max = records[i].date.month;
			nmax = i;
		};
	};

	struct Record bufer = records[nmin];
	records[nmin] = records[nmax];
	records[nmax] = bufer;
}

int  findIndex(struct Record* records, const struct Date date) {
	int ind = -1;
	for (int i = 0; i < 3; i++) {
		if (records[i].date.year == date.year && records[i].date.month == date.month && records[i].date.day == date.day)
			ind = i;
	}
	return ind;
};

void addItem(Record data)
{
	struct node* newItem = new node();
	newItem->data = data;
	if (countItem == 0) {
		newItem->next = NULL;
	}
	else
	{
		newItem->next = myHead;
	}
	myHead = newItem;
	countItem++;
}

void insertItem(int index, Record data) {
	if (not (index >= 0 and index <= countItem and countItem >= 0))
		return;
	if (index == 0) {
		addItem(data);
	}
	else {
		struct node* current = myHead;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node* newItem = new node();
		newItem->data = data;
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}

void editItem(int index, Record data) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		current->data = data;
	}
	else {
		cout << endl << "Ошибка индекс не в диапазоне";
	}
}

void deleteItem(int index) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		struct node* old;
		if (index == 0) {
			old = myHead;
			myHead = current->next;
			delete old;
			countItem--;
		}
		else {
			int i = 0;
			while (current) {
				if (i == index - 1) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countItem--;
					break;
				}
				i++;
				current = current->next;
			}
		}
	}

}


void DrawWithList() {
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
	struct node* current = myHead;
	while (current) {
		cout << left << "|"; cout.width(15); cout << left << current->data.name;
		cout << left << "|"; cout.width(15); cout << left << current->data.manufacturer;
		cout << left << "|+"; cout.width(15); cout << left << current->data.number;
		std::cout.precision(2);
		cout << left << "|"; cout.width(14); cout << left << fixed << current->data.price;
		PrintDate(current->data.date.day, current->data.date.month, current->data.date.year);
		cout.width(80); cout.fill('-'); cout << left << "|"; cout << left << "|" << endl;

		cout.fill(' ');
		current = current->next;
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


	MinMax(records);

	PrintTable(records);

	cout << "Практика № 3 Динамический список" << endl;
	addItem(records[0]);
	addItem(records[1]);
	addItem(records[2]);
	DrawWithList();
	struct Record newRecord = { "BestOffice", "Moon", 1999, 936.50, {01,02,2023} };
	insertItem(1, newRecord);
	DrawWithList();
	deleteItem(3);
	DrawWithList();
	struct Record editRecord = { "LiteOffice", "Earth", 1994, 780.35, {01,02,2023} };
	editItem(1, editRecord);
	DrawWithList();
}
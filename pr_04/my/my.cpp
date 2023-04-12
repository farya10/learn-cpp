#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>

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
	char number[5];
	char price[10];
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
	{ "Office", "Microsoft", "4", "870.99", {11,01,2011} },
	{ "SmartSute", "Lotus", "5", "1020.99", {21,12,2012} },
	{ "StarOffice", "Sun", "4", "9.99", {21,10,2020} },
	};

	cout << "Вывод таблицы из нулевой практики: \n";

	PrintTable(records);

	// 1) Записываем в файл данные из таблицы (в текстовый)
	FILE* Fisunova;
	fopen_s(&Fisunova, "Fisunova.txt", "w+");
	for (int i = 0; i < 3; i++) {
		fprintf(Fisunova, "%s %s %s %s %d %d %d \n", \
			records[i].name, records[i].manufacturer, \
			records[i].number, records[i].price, \
			records[i].date.day, records[i].date.month, records[i].date.year);
	}
	fclose(Fisunova);

	// 2) Считать 3 записи из файла в текстовом формате
	fopen_s(&Fisunova, "Fisunova.txt", "r");

	Record rdRecords[4];

	for (int i = 0; i < 3; i++) {
		fscanf_s(Fisunova, "%s", &rdRecords[i].name, _countof(rdRecords[i].name));
		fscanf_s(Fisunova, "%s", &rdRecords[i].manufacturer, _countof(rdRecords[i].manufacturer));
		fscanf_s(Fisunova, "%s", &rdRecords[i].number, _countof(rdRecords[i].number));
		fscanf_s(Fisunova, "%s", &rdRecords[i].price, _countof(rdRecords[i].price));
		fscanf_s(Fisunova, "%d", &rdRecords[i].date.day);
		fscanf_s(Fisunova, "%d", &rdRecords[i].date.month);
		fscanf_s(Fisunova, "%d", &rdRecords[i].date.year);
	}
	fclose(Fisunova);

	cout << "\n";
	cout << "Вывод таблицы с данными из файла(Текстовый):";
	cout << "\n";
	cout << "\n";

	PrintTable(records);

	// Записать 3 записи (три строки(records) из таблицы практики 0) в файл в бинарном формате.
	FILE* Fisunovabin;
	fopen_s(&Fisunovabin, "Fisunovabin.bin", "w");
	fwrite(records, sizeof(records), 1, Fisunovabin);
	fclose(Fisunovabin);

	// Считать данные из файла бинарного формата
	fopen_s(&Fisunovabin, "Fisunovabin.bin", "rb");
	fread_s(rdRecords, sizeof(rdRecords), sizeof(rdRecords), 1, Fisunovabin);
	fclose(Fisunovabin);

	cout << "\n";
	cout << "Вывод таблицы с данными из файла(бинарный):";
	cout << "\n";
	cout << "\n";

	PrintTable(records);

	// Добавить новую запись в файл в бинарном формате (3 вариант) и прочитать файл
	Record t1Record[4];

	for (int i = 0; i < 3; i++) {
		t1Record[i] = records[i];
	}

	cout << "\n";
	cout << "Введите данные для 4 строки (дату вводить без точек и нулей): \n";
	cin >> t1Record[3].name >> t1Record[3].manufacturer >> t1Record[3].number >> t1Record[3].price >> t1Record[3].date.day >> t1Record[3].date.month >> t1Record[3].date.year;

	fopen_s(&Fisunovabin, "Fisunovabin.bin", "wb");
	fwrite(t1Record, sizeof(t1Record), 1, Fisunovabin);
	fclose(Fisunovabin);


	fopen_s(&Fisunovabin, "Fisunovabin.bin", "rb");
	fread_s(t1Record, sizeof(t1Record), sizeof(t1Record), 1, Fisunovabin);
	fclose(Fisunovabin);



	cout << "\n";
	cout << "Вывод таблицы с новой записью из бинарного файла: \n";
	cout << "\n";

	PrintTable(records);

	// 3 вариант. Заменить на удвоенное значение все четные целочисленные значения в файле.
	fopen_s(&Fisunovabin, "Fisunovabin.bin", "rb");

	for (int i = 0; i < 4; i++) {
		if ((int)rdRecords[i].number % 2 == 0) {
			strcpy(rdRecords[i].number, ("%s", (int)rdRecords[i].number * 2));
		}
	}

	fclose(Fisunovabin);

	fopen_s(&Fisunovabin, "Fisunovabin.bin", "wb+");
	fread_s(t1Record, sizeof(t1Record), sizeof(t1Record), 1, Fisunovabin);
	fclose(Fisunovabin);

	cout << "\n";
	cout << "Вывод таблицы с измененными: \n";
	cout << "\n";


	PrintTable(records);
}
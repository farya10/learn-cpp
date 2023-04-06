// var_4 
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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

	cout.width(80); cout.fill('-'); cout << "|"; cout << "|" << endl;

	cout.fill(' ');

	cout.width(16); cout << "|Office";
	cout.width(16); cout << "|Microsoft";
	cout.width(16); cout << "|4";
	cout.width(16); cout << "|870.99";
	cout.width(16); cout << "|11.01.2011";
	cout << '|' << endl;

	cout.width(80); cout.fill('-'); cout << "|"; cout << "|" << endl;

	cout.fill(' ');

	cout.width(16); cout << "|SmartSute";
	cout.width(16); cout << "|Lotus";
	cout.width(16); cout << "|5";
	cout.width(16); cout << "|1020.99";
	cout.width(16); cout << "|21.12.2012";
	cout << '|' << endl;

	cout.width(80); cout.fill('-'); cout << "|"; cout << "|" << endl;

	cout.fill(' ');


	cout.width(16); cout << "|StarOffice";
	cout.width(16); cout << "|Sun";
	cout.width(16); cout << "|4";
	cout.width(16); cout << "|9.99";
	cout.width(16); cout << "|21.10.2020";
	cout << '|' << endl;

	cout.width(80); cout.fill('-'); cout << "|"; cout << "|" << endl;

	cout.fill(' ');

	cout.fill(' '); cout.width(80); cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet"; cout << '|' << endl;

	cout << "-";  cout.width(80); cout.fill('-'); cout << "-" << endl;
}
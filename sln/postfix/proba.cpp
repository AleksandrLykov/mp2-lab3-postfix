#include "postfix.h"

void main () 
{
	setlocale(LC_ALL, "Russian");
	string vyrazh;
	string otvet;
    cout << "Ёта программа почти умеет переводить в постфиксную форму" << endl << "¬ведите выражение, которое необходимо перевести в постфиксную форму" << endl << "P.s. выражени€ могу состо€ть только из латинских букв и операций *,/,-,+,=,'(',')'" << endl;
	getline(cin,vyrazh);
	Postfix a(vyrazh);
	cout << "¬ведЄнное выражение: " << endl << vyrazh << endl << "ќтвет: " << endl;
	otvet = a.postfix();
	cout << otvet << endl;
	system("pause");
}
#include "postfix.h"

void main () 
{
	setlocale(LC_ALL, "Russian");
	string vyrazh;
	string otvet;
    cout << "Эта программа почти умеет переводить в постфиксную форму" << endl << "Введите выражение, которое необходимо перевести в постфиксную форму" << endl << "P.s. выражения могу состоять только из латинских букв и операций *,/,-,+,=,'(',')'" << endl << "Ну ещё и цифр" << endl;
	getline(cin,vyrazh);
	Postfix a(vyrazh);
	cout << "Введённое выражение: " << endl << vyrazh << endl << "Ответ: " << endl;
	otvet = a.postfix();
	cout << otvet << endl;
	system("pause");
}
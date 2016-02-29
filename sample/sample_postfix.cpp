#include <iostream>
#include "postfix.h"
#include "postfix.cpp"

using namespace std;


int main(void)
{
	string str;
	setlocale(LC_ALL, "Russian");
	cout << "��� ��������� ����� ����� ���������� � ����������� �����" << endl << 
		"������� ���������, ������� ���������� ��������� � ����������� �����" << endl << 
		"P.s. ��������� ����� �������� ������ �� ��������� ���� � �������� *,/,-,+,=,'(',')'" 
		<< endl << "�� ��� � ����" << endl;
	getline(cin, str);
	map<char, ExpType> m;
	Postfix p;
	string str1;
	try
	{
		str1 = p.Record(str);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}

	cout << "�������� �����: " << str1 << endl;
	ExpType result;
	try
	{
		result = p.Count(str1, m);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}
	cout << "���������: " << result << endl;
	return 0;
}
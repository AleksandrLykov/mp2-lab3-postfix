#include "postfix.h"

void main () 
{
	setlocale(LC_ALL, "Russian");
	string vyrazh;
	string otvet;
    cout << "��� ��������� ����� ����� ���������� � ����������� �����" << endl << "������� ���������, ������� ���������� ��������� � ����������� �����" << endl << "P.s. ��������� ���� �������� ������ �� ��������� ���� � �������� *,/,-,+,=,'(',')'" << endl << "�� ��� � ����" << endl;
	getline(cin,vyrazh);
	Postfix a(vyrazh);
	cout << "�������� ���������: " << endl << vyrazh << endl << "�����: " << endl;
	otvet = a.postfix();
	cout << otvet << endl;
	system("pause");
}
#include "list.h"

void main()
{    
	setlocale(LC_ALL, "Russian");
    list<int> *l = new list<int>;
    cout << "�����������" << endl;
    l->print();
    cout << "������� ��������" << endl;
    l->push(1);
    l->print();
	cout << "�������� ���������� � ����� ������" << endl;
    l->pushend(3);
    l->print();
    cout << "�������� ���������� ��������" << endl;
    l->pushafter(1, 2);
    l->print();
    cout << "�������� ��������" << endl;
    l->remove(1);
    l->print();
    cout << endl;
	system ("pause");
}
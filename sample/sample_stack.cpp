#include "stack.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	Stack<int>* s = new Stack<int>();
	cout << "������� ������" << endl;
	int n;
	cin >> n;
	int k;
	for (i=0; i < n; i++)
	{
		cout << "������� ���� ��������: ";
		cin >> k;
		s->Push(k);
	}
	cout << endl << "�� �������� " << n << " ��������(-��) " << endl;
	s->Print();	
	cout << endl << "������� ���� ������� " << endl;
	s->Pop();
	s->Print();
	return;
}
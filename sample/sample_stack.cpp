#include "stack.h"

void main()
{    
    setlocale(LC_ALL, "Russian");
	stack<int>* s = new stack<int>;
    cout << "�������� isempty" << endl;
    cout << s->isempty() << endl;
	s->push(1);
	s->push(2);
	s->push(3);
    cout <<"���������" << endl;
    s->print();
    cout << endl <<"�������� pop�" << endl;
    s->pop();
    s->print();
	system("pause");
}
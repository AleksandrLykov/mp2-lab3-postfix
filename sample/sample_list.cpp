#include "list.h"

void main()
{    
	setlocale(LC_ALL, "Russian");
    list<int> *l = new list<int>;
    cout << "Изначальный" << endl;
    l->print();
    cout << "добавка элемента" << endl;
    l->push(1);
    l->print();
	cout << "Проверка добавления в конце списка" << endl;
    l->pushend(3);
    l->print();
    cout << "Проверка добавления элемента" << endl;
    l->pushafter(1, 2);
    l->print();
    cout << "Проверка удаления" << endl;
    l->remove(1);
    l->print();
    cout << endl;
	system ("pause");
}
#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "stack.h"
#include <string>

using namespace std;

class Postfix {
private:
	stack<char>* res; //первый стек
	stack<char>* oper;	//второй стек
	string v1; //начальные данные
public:
	Postfix(const string&);
	~Postfix();
	int operaci (const char);
	int prioritet (const char); //приоритет операции
	char skobka (); // если попалась скобка
	char ponizhenie (char a); // если приоритет новой операции меньше старого
	string printres (); //вывод результата
	string postfix (); //сам перевод
	void vichisl (string); //вычисление выражения
};


#endif
#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "list_stack.h"
#include <string>

using namespace std;

class Postfix {
private:
	stack<char>* res;
	stack<char>* oper;	
	string v1; // исходное выражение
	string v2; // готовое выражение
	int kolvo; // количество операций
public:
	Postfix();
	~Postfix();
	
	int prioritet(const char);
	int operand (const char);
	int operaci (const char); //приоритет операции
	char skobka (); // если попалась скобка
	char priorit (char b); // если приоритет новой операции меньше старого
}


#endif
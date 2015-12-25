#include "postfix.h"

Postfix::Postfix() {
	oper = new stack<char>();
	res = new stack<char>();
	v1 = "";
	v2 = "";
	kolvo = 0;
}

Postfix::~Postfix(void) {
	delete res;
	delete oper;
}

int Postfix::operaci(const char a) 
{
	switch (a)
	{
	case '*':
		return 3;
	case '/':
		return 3;
	case '+':
		return 2;
	case '-':
		return 2;
	case '(':
		return 1;
	default:
		return 0;
	}
}

int Postfix::operand(const char a) 
{
	if (a == ' ') 
		return 0;
	return 1;
}

char Postfix::skobka()
{
	char a = oper->pop();
	while (a != '(')
	{
		res->push(a);
		a = oper->pop();
	}
	a = oper->pop();
	return (a);
}

char Postfix::priorit(char a) 
{
	char b = oper->pop();
	while ((a

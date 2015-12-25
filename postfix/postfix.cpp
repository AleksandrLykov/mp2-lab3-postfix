#include "postfix.h"

Postfix::Postfix(const string& a) 
{
	res = new stack<char>();
	oper = new stack<char>();
	v1 = a;
}

Postfix::~Postfix() {
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
	case ')':
		return 1;
	}
}

int Postfix::prioritet(const char a) 
{
	if ((a == '*') || (a == '/') || (a == '+') || (a == '-') || (a == '(') || (a == ')')) 
		return operaci(a);
	if (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z')))
	return 0;
	else throw "a";
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

char Postfix::ponizhenie(char a) 
{
	char b = oper->pop();
	while ((operaci(a)) < (operaci(b)) || (oper->isempty() != true)) 
	{
		res->push(b);
		b = oper->pop();
	}
	if (operaci(a) < operaci(b))
		res->push(b);
	else oper ->push(b);
	return a;
}

string Postfix::printres()
{
	int n=0;
	if (oper->isempty() == 0)
		throw ("OPERACII NE KONCHILIS'");
	while (res->isempty() != 1)
	{
		oper->push(res->pop());
		n++;
	}
	string v;
	while (oper->isempty() != 1)
		v.push_back(oper->pop());	
	return v;
}

string Postfix::postfix () 
{
	if (v1 == "")
		throw ("ZADANa PYSTAYA STROKA"); 
	char a;
	char tmp;
	int n=0, m=0; //n - приоритет данной операции, m - приоритет прошлой операции
	for (int i=0; i<v1.length();i++) 
	{
		a = v1[i];
		n = prioritet(a);
		if (n == 0)
			res->push(a);
		else 
		{
			if (a == ')') 
				a = skobka();
			else if ((n < m) && (a != '('))
				a = ponizhenie(a);
			oper->push(a);
			m = n;
		}
	}
	if (oper->isempty() != true)
		while (oper->isempty() != true)
		{
			tmp = oper->pop();
			res->push(tmp);
		}
	string v2 = printres();
	return v2;
}

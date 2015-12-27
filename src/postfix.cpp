#include "postfix.h"

#include <map>

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
	if (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z')) || (a == ' ') || ((a >=-1000) && (a <= 1000))) 
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
	
	return (a);
}

char Postfix::ponizhenie(char a) 
{
	char b = oper->pop();
	while ((operaci(a)) < (operaci(b)) && (oper->isempty() != true)) 
	{
		res->push(b);
		b = oper->pop();
	}
	if (operaci(a) <= operaci(b))
		res->push(b);
	else oper -> push(b);
	return a;
}

string Postfix::printres()
{
	char a;
	if (oper->isempty() == 0)
		throw ("OPERACII NE KONCHILIS'");
	while (res->isempty() != 1)
	{
		a = res->pop();	
		while (a == '(')
			a = res->pop();			
		oper->push(a);
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
 
void Postfix::vichisl (string v2) 
{
	string t;
	int n = 0; 
	char z;
	map<char, float> a;
	for (int i=0; i<v2.length();i++)
		if (prioritet(v2[i]) == 0)
		{
			t.push_back(v2[i]);
			n++;
		}
	for (int i=0; i<n; i++)
	{
		cout << "Введите " << t[i] << ": " << endl;
		z = t[i];
		cin >> a[t[i]];
	}
	
	stack<float> result;
	char tmp;
	float left;
	float right;
	for (int i = 0; i < v2.length(); i++) 
	{
		tmp = v2[i];
		if (prioritet(v2[i]) == 0) 		
			result.push(a[tmp]);
		if (prioritet(v2[i]) != 0)
		{
			right = result.pop();		
			left = result.pop();
			if (tmp == '+')
				result.push(left + right);
			if (tmp == '-')
				result.push(left - right);
			if (tmp == '*')
				result.push(left*right);
			if (tmp == '/')
				result.push(left / right);
		}
	}
	float res = result.pop();
	cout << "Otvet" << endl << res << endl;		
}

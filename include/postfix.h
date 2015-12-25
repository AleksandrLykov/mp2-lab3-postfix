#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "list_stack.h"
#include <string>

using namespace std;

class Postfix {
private:
	stack<char>* res;
	stack<char>* oper;	
	string v1; // �������� ���������
	string v2; // ������� ���������
	int kolvo; // ���������� ��������
public:
	Postfix();
	~Postfix();
	
	int prioritet(const char);
	int operand (const char);
	int operaci (const char); //��������� ��������
	char skobka (); // ���� �������� ������
	char priorit (char b); // ���� ��������� ����� �������� ������ �������
}


#endif
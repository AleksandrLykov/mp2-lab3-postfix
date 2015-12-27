#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "stack.h"
#include <string>

using namespace std;

class Postfix {
private:
	stack<char>* res; //������ ����
	stack<char>* oper;	//������ ����
	string v1; //��������� ������
public:
	Postfix(const string&);
	~Postfix();
	int operaci (const char);
	int prioritet (const char); //��������� ��������
	char skobka (); // ���� �������� ������
	char ponizhenie (char a); // ���� ��������� ����� �������� ������ �������
	string printres (); //����� ����������
	string postfix (); //��� �������
	void vichisl (string); //���������� ���������
};


#endif
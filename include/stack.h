#ifndef __STACK_H__
#define __STACK_H__

#include "list.h"

template <class PType>
class stack {
private: 
	list<PType>* pList;
public:
	stack ();
	stack (const stack<PType>&);
	~stack();
	bool isfull () const;
	bool isempty () const;
	void push (const PType&);
	PType pop(void);
	void print();
};

template <class PType>
stack<PType>::stack ()
{
	pList = new list<PType>();
}

template <class PType>
stack<PType>::stack(const stack<PType>& st)
{
	pList = new list<PType>(*st.pList);
}

template <class PType>
stack<PType>::~stack(){
	delete pList;
}

//�������� �� �������
template <class PType>
bool stack<PType>::isfull() const{
	Node<PType>* tmp;
	try{
		tmp = new Node<PType>;
	} 
	catch (...) {
		return true;
	}
	delete tmp;
	return false;
}

//�������� �� �������
template <class PType>
bool stack<PType>::isempty() const
{
	return (pList->getfirst() == 0);
}

//���������� �������� � ����
template <class PType>
void stack<PType>::push(const PType& key){
	if (isfull())
		throw("STACK PEREPOLNEN");
	pList->push(key);
}

//�������� �� �����
template <class PType>
PType stack<PType>::pop(void)
{
	if (isempty() == 1)
		throw "asd";
	PType tmp = pList->getfirst()->key;
	pList->remove(tmp);
	return tmp;
}

//������ �����
template <class PType>
void stack<PType>::print()
{
    stack<PType>* s = new stack<PType>(*this);
    while (s->isempty() != 1)
        cout << s->pop() << " -> ";
}

#endif
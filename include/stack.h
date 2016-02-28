#ifndef __STACK_H__
#define __STACK_H__

#include "list.h"

template <class PType>
class Stack
{
private:
	list<PType> *List;
public:
	Stack();
	Stack(const Stack<PType>&);
	~Stack();
	int IsEmpty(void)const;
	int IsFull(void)const;
	void Push(const PType);
	PType Pop();
	int operator==(const Stack<PType>& s)const;
	int operator!=(const Stack<PType>& s)const;
	void Print()const;
	PType GetKey();
};

template<class PType>
Stack<PType>::Stack()
{
	List = new list<PType>();
}

template<class PType>
Stack<PType>::~Stack()
{
	delete List;
}

template<class PType>
Stack<PType>::Stack(const Stack<PType>& stack)
{
	List = new list<PType>(*(stack.List));
}

template<class PType>
int Stack<PType>::IsEmpty(void)const
{
	return(List->getfirst() == 0);
}

template<class PType>
int Stack<PType>::IsFull(void)const
{
	Node<PType> *tmp;
	try
	{
		tmp = new Node<PType>;
	}
	catch (...)
	{
		return 1;
	}
	delete tmp;
	return 0;
}

template<class PType>
void Stack<PType>::Push(const PType k)
{
	if (IsFull())
		throw
		exception("Stack is full");
	List->push(k);
}

template<class PType>
PType Stack<PType>::Pop()
{
	if (IsEmpty())
		throw
			exception ("Stack is empty");
	PType tmp = List->getfirst()->key;
	List->remove(tmp);
	return tmp;
}

template <class PType>
int Stack<PType>::operator==(const Stack<PType>& s)const
{
	return (*List == *(s.List));
}

template <class PType>
int Stack<PType>::operator!= (const Stack<PType>& s)const
{
	return (*List != *(s.List));
}

template <class PType>
void Stack<PType>::Print()const
{
	Stack<PType>* s = new Stack<PType>(*this);
	while (!(s->IsEmpty()))
		cout << s->Pop() << endl;
}

template <class PType>
PType Stack<PType>::GetKey()
{
	if (IsEmpty())
		throw
		exception ("Stack is empty");
	return List->getfirst()->key;
}

#endif
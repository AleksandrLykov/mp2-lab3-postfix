#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <cstdlib>

const int MAX_STRING = 100000;

using namespace std;

template <class PType>
class Node {
public:
	PType key;
	Node<PType>* pNext;
	Node() {pNext = 0;};
	Node(const PType& k) {key = k; pNext = 0;};
};

template <class PType>
class list {
private:
	Node<PType>* pFirst;
public:
	list (void);
	~list();
	list (const list<PType> &);	
	void push (const PType& tmp);
	Node<PType>* search(const PType& key);
	void pushafter (const PType& s, const PType& key);
	void pushbefore (const PType& s, const PType& key);
	void pushend (const PType&);
	void remove (const PType& key);
	Node<PType>* getfirst(void);
	void print();
};


template <class PType> 
list<PType>::list(void) {
	pFirst = 0;
}

template <class PType> 
list<PType>::list(const list<PType>& l) 
{
	pFirst = 0;
	Node<PType>* tmp = l.pFirst;
	while (tmp != 0)
	{
		pushend(tmp->key);
		tmp = tmp->pNext;
	}
}


template <class PType> 
list<PType>::~list() {
	delete pFirst;
}

// добавление элемента в начало списка
template <class PType>
void list<PType>::push (const PType& tmp) 
{
	Node<PType>* n = new Node<PType>;
	n->key = tmp;
	n->pNext = pFirst;
	pFirst = n;
}

//Поиск элемента без предыдущего
template <class PType>
Node<PType>* list<PType>::search (const PType& k)
{
	Node<PType>* elem = pFirst;
	while (elem != 0) 
	{
		if (elem->key == k)
			break;
		elem = elem->pNext;
	}
	if (elem == 0)
		return 0;
	return elem;
}

// добавление элемента после элемента с ключом s
template <class PType>
void list<PType>::pushafter (const PType& s, const PType& key)
{
	Node<PType>* elem = search(s);
	if (elem == 0)
		throw ("ELEMENT NE NAIDEN");
	Node<PType>* tmp;
	tmp = elem->pNext;
	Node<PType>* node = new Node<PType>(key);
	elem->pNext = node;
	node->pNext = tmp;
}

// добавление элемента перед элементом с ключом s
template <class PType>
void list<PType>::pushbefore (const PType& s, const PType& key)
{
	if (pFirst->key == key){ 
		push(key);
		return;
	}
	Node<PType>* elem = pFirst->pNext;
	Node<PType>* tmp = pFirst;
	while (elem != 0) 
	{
		if (elem->key == s)
			break;
		elem = elem->pNext;
		tmp = tmp->pNext;
	}
	if (elem == 0)
		throw ("ELEMENT NE NAIDEN");
	Node<PType>* tmp2 = elem->pNext;
	Node<PType>* node = new Node<PType>(key);
	tmp = node;
	tmp->pNext = elem;
	elem->pNext = tmp2;
}

// добавление элемента в конец списка
template <class PType> 
void list<PType>::pushend (const PType& key) 
{
	if (pFirst == 0)
	{
		push(key);
		return;
	}
	Node<PType>* node = new Node<PType>(key);
	Node<PType>* tmp = pFirst;
	while (tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = node;
}

//удаление элемента с ключом k
template <class PType>
void list<PType>::remove (const PType& k)
{
	if (pFirst->key == k){ 
		pFirst = pFirst->pNext;
		return;
	}
	Node<PType>* elem = pFirst->pNext;
	Node<PType>* tmp = pFirst;
	while (elem != 0) 
	{
		if (elem->key == k)
			break;
		elem = elem->pNext;
		tmp = tmp->pNext;
	}
	if (elem == 0)
		throw ("ELEMENT NE NAIDEN");
	 tmp->pNext = elem->pNext;
}

// получение указатеря на первый элемент списка
template <class PType>
Node<PType>* list<PType>::getfirst(void)
{
    return pFirst;
}

//печать списка
template <class PType>
void list<PType>::print()
{
    Node<PType>* a = pFirst;
    while (a!= 0) 
	{
        cout << a->key << " -> ";
        a = a->pNext;
    }
}

#endif

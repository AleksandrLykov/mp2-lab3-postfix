#include "postfix.h"
#include "list_stack.h"

#include <gtest.h>


TEST(list, can_create_list)
{
    ASSERT_NO_THROW(list<int> *a = new list<int>());
}

TEST(list, can_copy_list)
{
	list<int> *a = new list<int>();
	ASSERT_NO_THROW(list<int> *b = new list<int>(*a));
}

TEST(list, proveryaem_getfirst)
{
	list<int> *a = new list<int>();
	EXPECT_EQ(0, a->getfirst());
}

TEST(list, proverka_mozhno_li_pervyi_element_polychit)
{
	list<int> *a = new list<int>();
	a->push(5);
	Node<int>* tmp = a->getfirst();
	EXPECT_EQ(tmp->key,5);
}

TEST(list, throw_esli_net_elementa)
{
	list<int> *a = new list<int>();
	ASSERT_ANY_THROW(a->pushafter(5,6));
}

TEST(list, proverka_search)
{
	list<int> *a = new list<int>();
	a->push(5);
	a->push(9);
	a->push(3);
	Node<int>* tmp = a->search(5);
	Node<int>* tmp2 = new Node<int>();
	tmp2->key = 5;
	EXPECT_EQ(tmp2->key, tmp->key);
}

TEST(list, proverka_dobavleniya_posle)
{
	list<int> *a = new list<int>();
	a->push(5);
	Node<int>* tmp = new Node<int>;
	tmp->key = 7;
	a->pushafter(5, tmp->key);
	EXPECT_EQ(tmp->key, a->search(7)->key);
}

TEST(list, provarka_ydaleniya_elementa)
{
	list<int> *a = new list<int>();

	a->push(5);
	a->push(346);
	a->remove(5);
	ASSERT_EQ(346, a->search(346)->key);
}

TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(stack<int> *s = new stack<int>() );
}

TEST(Stack, proverka_ydaleniya_iz_pustogo_steka)
{
	stack<int> *a = new stack<int>();
	ASSERT_ANY_THROW(a->pop());
}

TEST(Stack, proverka_copirovaniya_steka)
{
	stack<int> *a = new stack<int>();
	ASSERT_NO_THROW(stack<int> *b = new stack<int>(*a));
}

TEST(Stack, proverka_isempty)
{
	stack<int> *a = new stack<int>();
	ASSERT_EQ(1, a->isempty());
}

TEST(Stack, proverka_isfull)
{
	stack<int> *a = new stack<int>();
	ASSERT_EQ(0, a->isfull());
}

TEST(Stack, proverka_pop)
{
	stack<int> *a = new stack<int>();
	a->push(123);
	a->push(11);
	int c = a->pop();
	EXPECT_EQ(c, 11);
}


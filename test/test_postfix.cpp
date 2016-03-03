#include "postfix.h"
#include "list.h"
#include "stack.h"
#include "postfix.cpp"

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

TEST(STACK, can_create_stack)
{
	ASSERT_NO_THROW(new Stack<int>());
}

TEST(STACK, can_check_emptiness)
{
	Stack<int>* s = new Stack<int>;
	EXPECT_EQ(1, s->IsEmpty());
}

TEST(STACK, throws_when_pop_from_empty_stack)
{
	Stack<int>* s = new Stack<int>;
	ASSERT_ANY_THROW(s->Pop());
}

TEST(STACK, can_check_fullness)
{
	Stack<int>* s = new Stack<int>;
	s->Push(5);
	EXPECT_EQ(0, s->IsFull());
}

TEST(STACK, can_push_element)
{
	Stack<int>* s = new Stack<int>;
	ASSERT_NO_THROW(s->Push(2));
}

TEST(STACK, can_copy_stack)
{
	Stack<int>* s = new Stack<int>;
	s->Push(6);
	ASSERT_NO_THROW(Stack<int>* s1 = new Stack<int>(*s));
}

TEST(STACK, copied_stack_is_equal_to_source_one)
{
	Stack<int>* s = new Stack<int>;
	s->Push(6);
	s->Print();
	Stack<int>* s1 = new Stack<int>(*s);
	s->Print();
	EXPECT_EQ(*s, *s1);
}

TEST(STACK, can_pop_element)
{
	Stack<int>* s = new Stack<int>();
	s->Push(4);
	s->Push(6);
	int tmp;
	ASSERT_NO_THROW(tmp = s->Pop());
	EXPECT_EQ(6, tmp);
}

TEST(STACK, compare_different_stacks_returns_false)
{
	Stack<int>* s = new Stack<int>();
	s->Push(4);
	s->Push(6);
	Stack<int>* s1 = new Stack<int>();
	s->Push(2);
	s->Push(3);
	EXPECT_NE(*s, *s1);
}

TEST(STACK, can_compare_different_stacks)
{
	Stack<int>* s = new Stack<int>();
	s->Push(4);
	s->Push(6);
	Stack<int>* s1 = new Stack<int>();
	s->Push(2);
	s->Push(3);
	ASSERT_NO_THROW(s == s1);
}

TEST(STACK, can_compare_equal_stacks)
{
	Stack<int>* s = new Stack<int>();
	s->Push(4);
	s->Push(6);
	Stack<int>* s1 = new Stack<int>();
	s->Push(4);
	s->Push(6);
	ASSERT_NO_THROW(s == s1);
}

TEST(POSTFIX, can_calculate)
{
	Postfix p;
	string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)";
	map<char, ExpType> m;
	m['a'] = 1;
	m['b'] = 5;
	m['c'] = 3;
	m['d'] = 4;
	m['f'] = 5;
	m['k'] = 10;
	m['l'] = 15;
	m['s'] = 5;
	EXPECT_EQ(1, p.Count(p.Record(str), m));
}

TEST(POSTFIX, can_record)
{
	Postfix p;
	string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)*k";
	string str1 = p.Record(str);
	EXPECT_EQ("abc+d-*dfc-/kl+s/-k*+", str1);
}

TEST(POSTFIX, throws_when_enter_anavailable_symbol)
{
	Postfix p;
	string str = "&";
	ASSERT_ANY_THROW(p.Record(str));
}

TEST(POSTFIX, throws_when_string_is_empty)
{
	Postfix p;
	string str = "";
	ASSERT_ANY_THROW(p.Record(str));
}

TEST(POSTFIX, throws_when_string_is_empty_when_count)
{
	Postfix p;
	string str = "";
	string str1;
	map<char, ExpType> m;
	m['a'] = 1;
	m['b'] = 5;
	m['c'] = 3;
	m['d'] = 4;
	m['f'] = 5;
	m['k'] = 10;
	m['l'] = 15;
	m['s'] = 5;
	ASSERT_ANY_THROW(str1 = p.Count(str, m));
}

TEST(POSTFIX, throws_when_divide_by_zero)
{
	Postfix p;
	string str = "a/f";
	string str1;
	map<char, ExpType> m;
	m['a'] = 1;
	m['f'] = 0;
	ASSERT_ANY_THROW(str1 = p.Count(str, m));
}
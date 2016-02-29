#include "postfix.h"
#include "list.h"
#include "stack.h"

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


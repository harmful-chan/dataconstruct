#include "CUnit/Basic.h" 
#include "link.h" 
#include <stdio.h>
LinkList list = NULL; 

int init_list() 
{ 
	return 0; 
} 

int clean_list()
{
	return 0;
}

void sequence_add_elm(int num)
{
	list = CreateLinkList();
	CU_ASSERT_PTR_NOT_NULL(list);
	for(int i = 0; i < num; i++)
	{
		Add(list, i);
	}
}

void sequence_destroy_elm()
{
	DestroyLinkList(list);
	CU_ASSERT_PTR_NULL(list);
}

void test_add()
{
	sequence_add_elm(0);
	for(int i = 0; i < 100; i++)
	{
		int ret = Add(list, i);
		CU_ASSERT_NOT_EQUAL(ret, -1);
		CU_ASSERT(ret >= 0);
	}
	sequence_destroy_elm();
}

void test_delete()
{
	
	sequence_add_elm(0);
	for(int i = 0; i < 100; i++)
	{
		int ret = Delete(list, 99-i);
		CU_ASSERT_EQUAL(ret, 99-i);
	}
	sequence_destroy_elm();
}

void test_get()
{
	sequence_add_elm(0);
	for(int i = 0; i < 100 ; i++)
	{
		LNode* p = Get(list, i);
		CU_ASSERT_PTR_NOT_EQUAL(p, NULL);
#if defined(HEAD_MODE)
		CU_ASSERT_EQUAL(p->data, 99-i);
#else
		CU_ASSERT_EQUAL(p->data,  i);
#endif
	}
	sequence_destroy_elm();
}

void test_insert()
{
	sequence_add_elm(100);
	int indexs[8] = {101, 99, 32, 19, 10, 7, 2, 0};
	for(int i = 0; i < 8; i++)
	{	
		int ret = Insert(list, indexs[i], 10086);
		switch(i)
		{
			case 0 : 
				CU_ASSERT_EQUAL(ret, -1);
				break;
			default:
				CU_ASSERT_EQUAL(ret, indexs[i]);
				break;
		}
		ret = Delete(list, indexs[i]);
	}
	sequence_destroy_elm();
}

void test_locate()
{
	sequence_add_elm(100);
	int indexs[8] = {101, 99, 32, 19, 10, 7, 2, 0};
	for(int i = 0; i < 8; i++)
	{	
		int ret = Insert(list, indexs[i], 10086);
		ret = Locate(list, 10086);
		switch(i)
		{
			case 0 : 
				CU_ASSERT_EQUAL(ret, -1);
				break;
			default:
				CU_ASSERT_EQUAL(ret, indexs[i]);
				break;
		}
		ret = Delete(list, indexs[i]);
	}
	sequence_destroy_elm();
}
void test_replace()
{

	sequence_add_elm(100);
	for(int i = 0; i < 50; i++)
	{
		int ret = Replace(list, i, 50-i);
		CU_ASSERT(ret >= 0);
		LNode* p = Get(list, i);
		CU_ASSERT_EQUAL(p->data, 50-i);
		
	}

	sequence_destroy_elm();
}




int main()
{
	CU_pSuite pSuite = NULL;
	if( CUE_SUCCESS != CU_initialize_registry() )
		return CU_get_error();

	pSuite = CU_add_suite("list_suite", init_list, clean_list);
	if( pSuite ==NULL )
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	CU_add_test(pSuite, "test add", test_add);
	CU_add_test(pSuite, "test delete", test_delete);
	CU_add_test(pSuite, "test get", test_get);
	
	CU_add_test(pSuite, "test insert", test_insert);
	CU_add_test(pSuite, "test local", test_locate);

	CU_add_test(pSuite, "test replace", test_replace);

		
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
	
}



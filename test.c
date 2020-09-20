#include "CUnit/Basic.h"
#include "link.h"


LinkList list = NULL;

int init_list()
{
	list = CreateLinkList();
	return list != NULL ? 0 : -1;
}

int clean_list()
{
	int ret = DestroyLinkList(list);
	return ret >= 0 ? 0 : -1;
}

void test_add_and_get()
{
	for(int i = 0; i < 20; i++)
	{
		CU_ASSERT(Add(list, i) >= 0);
	}
	for(int i = 0; i < 20 ; i++)
	{
#if defined(HEAD_MODE)
		CU_ASSERT(Get(list, i)->data == (19-i));
#else
		CU_ASSERT(Get(list, i)->data == i);
#endif
	}
}

void test_insert_and_locate()
{
	int indexs[6] = {32, 19, 10, 7, 2, 0};
	for(int i = 0; i < 1; i++)
	{
		CU_ASSERT(Insert(list, indexs[i], 10086) < 0);
	}
	for(int i = 1; i < 6; i++)
	{
		
		CU_ASSERT(Insert(list, indexs[i], 10086) >= 0);
		CU_ASSERT(Locate(list, 10086) >= 0);
		CU_ASSERT(Locate(list, 10086) == indexs[i]);
	}
}

void test_replace()
{
	for(int i = 0; i < 10; i++)
	{
		CU_ASSERT(Replace(list, i, 90-i) >= 0);
		CU_ASSERT(Get(list, i)->data == (90-i));
	}
}

void test_delete()
{
	for(int i = 0; i < 10; i++)
	{
		CU_ASSERT(Insert(list, i, -99) >= 0);
		CU_ASSERT(Delete(list, i) >= 0);
		CU_ASSERT(Get(list, i)->data != -99);
	}
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
	
	CU_add_test(pSuite, "test add and get", test_add_and_get);
	
	CU_add_test(pSuite, "test insert and local", \
		test_insert_and_locate);

	CU_add_test(pSuite, "test replace", test_replace);

	CU_add_test(pSuite, "test delete", test_delete);
		
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
	
}



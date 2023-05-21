#include <CUnit/Basic.h>
#include <CUnit/TestDB.h>
#include <CUnit/CUnit.h>
#include "UnitTest.h"
int	main()
{
	int ret;

	//file name
	CU_pSuite	testSuite;
	CU_initialize_registry();
	testSuite = CU_add_suite("file name test", NULL, NULL);
	CU_add_test(testSuite, "file name", test_file_name);

	CU_basic_run_tests();
	ret = CU_get_number_of_failures();
	CU_cleanup_registry();
	return (ret);
}
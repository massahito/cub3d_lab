#include "UnitTest.h"
#include <CUnit/CUnit.h>

void test_file_name(void)
{

	CU_ASSERT_EQUAL(0, is_file_name_ok("hello"));
	CU_ASSERT_EQUAL(1, is_file_name_ok("hello.cub"));
	CU_ASSERT_EQUAL(0, is_file_name_ok("hello."));
	CU_ASSERT_EQUAL(0, is_file_name_ok("hello.c"));
	CU_ASSERT_EQUAL(0, is_file_name_ok("hello.cu"));
	CU_ASSERT_EQUAL(1, is_file_name_ok(".cub"));
	CU_ASSERT_EQUAL(0, is_file_name_ok("halllo"));
}

void	map_info(void)
{
	CU_ASSERT_EQUAL(0, );
}
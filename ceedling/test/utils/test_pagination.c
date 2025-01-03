#include "pagination_util.h"
#include "unity.h"
#include <string.h>

void test_pagination(void) {
   pagination_t pagination;

   const uint8_t itemsQuantity = 14;
   const uint8_t maxItemsPerPage = 5;
   TEST_ASSERT_EQUAL(ERROR_NONE, pag_Init(&pagination, itemsQuantity, maxItemsPerPage));
   TEST_ASSERT_EQUAL(3, pagination.pagesQuantity);
   TEST_ASSERT_EQUAL(5, pagination.maxItemsPerPage);
   TEST_ASSERT_EQUAL(4, pagination.itemsQuantityOnLastPage);

   TEST_ASSERT_TRUE(pag_IsOnFirstPage(&pagination));
   TEST_ASSERT_FALSE(pag_IsOnLastPage(&pagination));
   TEST_ASSERT_EQUAL(0, pag_GetFirstItemIndexOnCurrentPage(&pagination));
   TEST_ASSERT_EQUAL(5, pag_GetItemsQuantityOnCurrentPage(&pagination));
   
   pag_GoToNextPage(&pagination);
   TEST_ASSERT_FALSE(pag_IsOnFirstPage(&pagination));
   TEST_ASSERT_FALSE(pag_IsOnLastPage(&pagination));
   TEST_ASSERT_EQUAL(5, pag_GetFirstItemIndexOnCurrentPage(&pagination));
   TEST_ASSERT_EQUAL(5, pag_GetItemsQuantityOnCurrentPage(&pagination));

   pag_GoToNextPage(&pagination);
   TEST_ASSERT_FALSE(pag_IsOnFirstPage(&pagination));
   TEST_ASSERT_TRUE(pag_IsOnLastPage(&pagination));
   TEST_ASSERT_EQUAL(10, pag_GetFirstItemIndexOnCurrentPage(&pagination));
   TEST_ASSERT_EQUAL(4, pag_GetItemsQuantityOnCurrentPage(&pagination));

   pag_GoToNextPage(&pagination);
   TEST_ASSERT_FALSE(pag_IsOnFirstPage(&pagination));
   TEST_ASSERT_TRUE(pag_IsOnLastPage(&pagination));
   TEST_ASSERT_EQUAL(10, pag_GetFirstItemIndexOnCurrentPage(&pagination));
   TEST_ASSERT_EQUAL(4, pag_GetItemsQuantityOnCurrentPage(&pagination));

   pag_GoToPreviousPage(&pagination);
   TEST_ASSERT_FALSE(pag_IsOnFirstPage(&pagination));
   TEST_ASSERT_FALSE(pag_IsOnLastPage(&pagination));
   TEST_ASSERT_EQUAL(5, pag_GetFirstItemIndexOnCurrentPage(&pagination));
   TEST_ASSERT_EQUAL(5, pag_GetItemsQuantityOnCurrentPage(&pagination));

   pag_GoToPreviousPage(&pagination);
   TEST_ASSERT_TRUE(pag_IsOnFirstPage(&pagination));
   TEST_ASSERT_FALSE(pag_IsOnLastPage(&pagination));
   TEST_ASSERT_EQUAL(0, pag_GetFirstItemIndexOnCurrentPage(&pagination));
   TEST_ASSERT_EQUAL(5, pag_GetItemsQuantityOnCurrentPage(&pagination));

   pag_GoToPreviousPage(&pagination);
   TEST_ASSERT_TRUE(pag_IsOnFirstPage(&pagination));
   TEST_ASSERT_FALSE(pag_IsOnLastPage(&pagination));
   TEST_ASSERT_EQUAL(0, pag_GetFirstItemIndexOnCurrentPage(&pagination));
   TEST_ASSERT_EQUAL(5, pag_GetItemsQuantityOnCurrentPage(&pagination));
}

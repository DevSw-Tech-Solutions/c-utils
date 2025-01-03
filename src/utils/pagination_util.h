#ifndef _PAGINATION_UTIL_H_
#define _PAGINATION_UTIL_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "error_util.h"

// Public Defines ------------------------------------------------------------------------------------------------------

typedef struct {
   const int currentPage;
   const int itemsQuantity;
   const int maxItemsPerPage;
   const int pagesQuantity;
   const int itemsQuantityOnLastPage;
} pagination_t;

// Public Typedefs and Structures --------------------------------------------------------------------------------------

// Public Variables (externs) ------------------------------------------------------------------------------------------

// Public Functions Declarations ---------------------------------------------------------------------------------------

error_t pag_Init(pagination_t *pObject, int itemsQuantity, int maxItemsPerPage);
void pag_GoToFirstPage(pagination_t *pObject);
void pag_GoToLastPage(pagination_t *pObject);
void pag_GoToNextPage(pagination_t *pObject);
void pag_GoToPreviousPage(pagination_t *pObject);
bool pag_IsOnFirstPage(pagination_t *pObject);
bool pag_IsOnLastPage(pagination_t *pObject);
int pag_GetFirstItemIndexOnCurrentPage(pagination_t *pObject);
int pag_GetItemsQuantityOnCurrentPage(pagination_t *pObject);

#endif

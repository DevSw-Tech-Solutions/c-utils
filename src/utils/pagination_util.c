#include "pagination_util.h"
#include "lang_util.h"

// Private Defines -----------------------------------------------------------------------------------------------------

#include <string.h>

// Private Typedefs and Structures -------------------------------------------------------------------------------------

// Private Functions Declarations (statics) ----------------------------------------------------------------------------

// Private Variables (statics) -----------------------------------------------------------------------------------------

// Public Variables ----------------------------------------------------------------------------------------------------

// Public and Private Functions Definitions ----------------------------------------------------------------------------

error_t pag_Init(pagination_t *pObject, int itemsQuantity, int maxItemsPerPage) {
   IF_TRUE_RETURN_VAL(IS_POINTER_NULL(pObject) || itemsQuantity < 1 || maxItemsPerPage < 1, ERROR_PARAMETER);

   *((int *)&pObject->itemsQuantity) = itemsQuantity;
   *((int *)&pObject->maxItemsPerPage) = maxItemsPerPage;

   const int fullPagesQuantity = pObject->itemsQuantity / pObject->maxItemsPerPage;
   const bool isThereExtraNotFullPage = (pObject->itemsQuantity % pObject->maxItemsPerPage) > 0;
   *((int *) &pObject->pagesQuantity) = fullPagesQuantity + (isThereExtraNotFullPage ? 1 : 0);
   *((int *) &pObject->itemsQuantityOnLastPage) = isThereExtraNotFullPage ? pObject->itemsQuantity % pObject->maxItemsPerPage : pObject->maxItemsPerPage;

   pag_GoToFirstPage(pObject);
   return (ERROR_NONE);
}

void pag_GoToFirstPage(pagination_t *pObject) {
   *((int *) &pObject->currentPage) = 0;
}

void pag_GoToLastPage(pagination_t *pObject) {
   *((int *) &pObject->currentPage) = pObject->pagesQuantity - 1;
}

void pag_GoToNextPage(pagination_t *pObject) {
   if (!pag_IsOnLastPage(pObject)) {
      *((int *) &pObject->currentPage) += 1;
   }
}

void pag_GoToPreviousPage(pagination_t *pObject) {
   if (!pag_IsOnFirstPage(pObject)) {
      *((int *) &pObject->currentPage) -= 1;
   }
}

bool pag_IsOnFirstPage(pagination_t *pObject) {
   return (pObject->currentPage == 0);
}

bool pag_IsOnLastPage(pagination_t *pObject) {
   return (pObject->currentPage >= (pObject->pagesQuantity - 1));
}

int pag_GetFirstItemIndexOnCurrentPage(pagination_t *pObject) {
   return (pObject->currentPage * pObject->maxItemsPerPage);
}

int pag_GetItemsQuantityOnCurrentPage(pagination_t *pObject) {
   if (pag_IsOnLastPage(pObject)) {
      return (pObject->itemsQuantityOnLastPage);
   } else {
      return (pObject->maxItemsPerPage);
   }
}

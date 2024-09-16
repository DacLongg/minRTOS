#ifndef __LIST_H
#define __LIST_H

#ifdef __cplusplus
extern "C" {
#endif

//#include "main.h"
#include "stdint.h"
#include "stdlib.h"
#include "stm32f1xx_hal.h"
#include "string.h"


typedef struct List
{
	void *Objs;
	struct List * Next;
}List;

typedef struct
{
	List *_lists;
	uint16_t Numlist;
}MemList;


MemList * newMList(void);
List *newLists(uint8_t pos);
uint8_t List_AddObj(MemList *mlist, uint16_t pos, void * Obj);
uint8_t List_GetObj(MemList *mlist, uint16_t pos, void ** Obj);
uint8_t List_deleteObj(MemList *mlist, void *Obj);
void *List_PtrObj(MemList *mlist, uint16_t pos);

#ifdef __cplusplus
}
#endif

#endif

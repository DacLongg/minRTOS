#include "list.h"

MemList * newMList(void)
{
	MemList * _newMList = (MemList *)malloc(sizeof(MemList));
	_newMList->_lists = NULL;
	_newMList->Numlist = 0;
	return _newMList;
}

List *newLists(uint8_t pos)
{
	List * _newList = (List *)malloc(sizeof(List));
	_newList->Objs = NULL;
	_newList->Next = NULL;
	return _newList;
}

uint8_t List_AddObj(MemList *mlist, uint16_t pos, void * Obj)
{
	List *__list = mlist->_lists;
	List *_list = __list;
	List * newlist = NULL;
	uint16_t count = 0;
	if(pos > mlist->Numlist && mlist->Numlist != 0)
	{
		while(__list != NULL)
		{
			_list = __list;
			__list = __list->Next;
			if(++ count == mlist->Numlist)
			{
				break;
			}
		}
		newlist = newLists(0);
		newlist->Objs = Obj;
		_list->Next = newlist;
	}
	else if(pos == 0 || mlist->Numlist == 0)
	{
		newlist = newLists(0);
		newlist->Objs = Obj;
		newlist->Next = mlist->_lists;
		mlist->_lists = newlist;
	}
	else
	{
		while(__list != NULL)
		{
			_list = __list;
			__list = __list->Next;
			if(++count == pos)
			{
				break;
			}
		}
		newlist = newLists(0);
		newlist->Objs = Obj;
		_list->Next = newlist;
		newlist->Next = __list;

	}
	mlist->Numlist ++;
	return 0;
}
uint8_t List_GetObj(MemList *mlist, uint16_t pos, void ** Obj)
{
	List *__list = mlist->_lists;
	List *_list = __list;
	uint16_t count = 0;
	if(mlist->Numlist == 0)
	{
		return 0;
	}
	if(mlist->Numlist == 1)
	{
		*Obj = __list->Objs;
		free(mlist->_lists);
		mlist->_lists = NULL;
	}
	else if(pos > mlist->Numlist)
	{
		while(__list != NULL)
		{
			if(++ count == mlist->Numlist)
			{
				break;
			}
			_list = __list;
			__list = __list->Next;

		}
		*Obj = __list->Objs;
		free(_list->Next);
		_list->Next = NULL;
	}
	else if(pos == 0)
	{
		* Obj = __list->Objs;
		_list = _list->Next;
		__list->Objs = NULL;
		free(__list);
		__list = NULL;
		mlist->_lists = _list;

	}
	else
	{
		while(__list != NULL)
		{
			_list = __list;
			__list = __list->Next;
			if(++count == pos)
			{
				break;
			}
		}
		* Obj = __list->Objs;
		__list->Objs = NULL;
		_list->Next = __list->Next;
		free(__list);
		__list =  NULL;

//		_list->Next = newlist;
//		newlist->Next = __list;

	}
	mlist->Numlist --;

	return 1;
}

void *List_PtrObj(MemList *mlist, uint16_t pos)
{
	List *_list = mlist->_lists;
	uint16_t count = 0;
	if(pos > mlist->Numlist || _list == NULL)
	{
		return NULL;
	}
	else if(pos == 0)
	{
		return _list->Objs;
	}
	while(_list != NULL)
	{
		_list = _list->Next;
		if(++ count == pos)
		{
			break;
		}
	}
	return _list->Objs;
}

uint8_t List_deleteObj(MemList *mlist, void *Obj)
{
	List *__list = mlist->_lists;
	List *_list = __list;
	while(__list != NULL)
	{
		if(__list->Objs == Obj)
		{
			__list->Objs = NULL;
			if(__list != mlist->_lists)
			{
				_list->Next = __list->Next;
				free(__list);
				__list = NULL;
			}
			else
			{
				_list = _list->Next;
				free(__list);
				__list = NULL;
				mlist->_lists = _list;
			}
			mlist->Numlist --;
			return 1;
		}
		_list = __list;
		__list = __list->Next;
		
	}
	return 0;
}

#include "mutex.h"

Mutex_t* Mutex_create(void)
{
	Mutex_t* newMutex = (Mutex_t *)malloc(sizeof(Mutex_t));
	newMutex->state = 1;
	newMutex->ListTaskwait = newMList();
	newMutex->TaskTake = NULL;
	return newMutex;
}
void Mutex_Take(Mutex_t* mutex)
{
	DOS_stop_kernel();
	OS_task_t * Tasptr = DOS_GetTaskRunnung();
	if(mutex->state == 1)
	{
		mutex->state = 0;
		mutex->TaskTake = Tasptr;
		DOS_start_kernel();
	}
	else
	{
		List_AddObj(mutex->ListTaskwait, 0xFF, Tasptr);
		DOS_start_kernel();
		DOS_TaskSuspend(Tasptr);
	}

}
void Mutex_Give(Mutex_t* mutex)
{
	DOS_stop_kernel();
	OS_task_t * TasRunptr = DOS_GetTaskRunnung();
	OS_task_t * TasWait_ptr = NULL;
	if(TasRunptr != mutex->TaskTake)
	{
		return;
	}
	if(List_GetObj(mutex->ListTaskwait, 0, (void *)&TasWait_ptr) == 1)
	{
		DOS_TaskResume(TasWait_ptr);
		mutex->TaskTake = TasWait_ptr;
	}

	DOS_start_kernel();
}

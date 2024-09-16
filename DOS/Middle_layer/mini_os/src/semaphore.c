#include "semaphore.h"


/*  function SMP_create receive 2 argument
 *  1. type of semaphore: SMP_BINARY or SMP_COUNTING
 *  2. if type is SMP_COUNTING u can choose number of semaphoe
 *
 *  and function return a semaphore object.
 */
Semaphore_t* SMP_create(SMP_Type smpType, uint8_t Numb_smp)
{
	Semaphore_t* newSMP = (Semaphore_t*)malloc(sizeof(Semaphore_t));
	newSMP->type = smpType;
	newSMP->value = Numb_smp;
	if(newSMP->type == SMP_BINARY)
	{
		newSMP->value = 1;
	}
	newSMP->ListTaskwait = newMList();
	return newSMP;
}

/*
 * after create semaphore object, u can use function SMP_Take(semaphore object)
 * 2 type commom use this function
 */
void SMP_Take(Semaphore_t* semaphore)
{
	DOS_stop_kernel();
	OS_task_t * Tasptr = DOS_GetTaskRunnung();
	if(-- semaphore->value < 0)
	{
		if(semaphore->type == SMP_BINARY)
		{
			semaphore->value = -1;
		}

		List_AddObj(semaphore->ListTaskwait, 0xFF, Tasptr);
		DOS_start_kernel();
		DOS_TaskSuspend(Tasptr);
	}
	DOS_start_kernel();

}

/*
 * after create semaphore object, u can use function SMP_Take(semaphore object)
 *
 */
void SMP_Give(Semaphore_t* semaphore)
{
	DOS_stop_kernel();
	OS_task_t * Tasptr = NULL;
	if( ++ semaphore->value <= 0)
	{
		if(List_GetObj(semaphore->ListTaskwait, 0, (void *)&Tasptr) == 1)
		{
			DOS_TaskResume(Tasptr);
		}
	}
	else if(semaphore->type == SMP_BINARY)
	{
		if(List_GetObj(semaphore->ListTaskwait, 0, (void *)&Tasptr) == 1)
		{
			semaphore->value = 0;
			DOS_TaskResume(Tasptr);
		}
		else
		{
			semaphore->value = 1;
		}
	}
	DOS_start_kernel();
}






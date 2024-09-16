#ifndef __MUTEX_H__
#define __MUTEX_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "miniOs_task.h"
#include "semaphore.h"


typedef struct
{
	MemList *ListTaskwait;
	OS_task_t *TaskTake;
	uint8_t state;
}Mutex_t;

Mutex_t* Mutex_create(void);
void Mutex_Take(Mutex_t* mutex);
void Mutex_Give(Mutex_t* mutex);

#ifdef __cplusplus
}
#endif

#endif

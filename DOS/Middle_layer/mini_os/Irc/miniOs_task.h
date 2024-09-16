#ifndef __MINI_OS_H__
#define __MINI_OS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "list.h"

typedef void(*Task_Function)(void);

typedef enum
{
	RUNNING,
	READY,
	SURPEND,
	BLOCK,
	NONE
}state_t;

typedef struct
{
	Task_Function function;
	const char * name;
	volatile uint32_t * StackPointer;
	volatile uint32_t *stackBase;
	volatile int32_t timeSleep;
	uint16_t stack_size;
	state_t state;
	uint8_t piority;
}OS_task_t;



void Init_os(void);

OS_task_t * task_create(Task_Function funct, const char *name, uint16_t stack_size, uint8_t piority);
OS_task_t * DOS_GetTaskRunnung(void);
void MiniOS_TaskIdle(void);
void DOS_start_kernel(void);
void DOS_stop_kernel(void);
void DOS_TaskSuspend(OS_task_t *task);
void DOS_TaskResume(OS_task_t *task);
void task_sleep(uint32_t time);

#ifdef __cplusplus
}
#endif

#endif

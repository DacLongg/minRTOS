#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "miniOs_task.h"


typedef enum
{
	SMP_BINARY,
	SMP_COUNTING,
}SMP_Type;

typedef struct
{
	MemList *ListTaskwait;
	int8_t value;
	SMP_Type type;
}Semaphore_t;

Semaphore_t* SMP_create(SMP_Type smpType, uint8_t Numb_smp);
void SMP_Take(Semaphore_t* semaphore);
void SMP_Give(Semaphore_t* semaphore);

#ifdef __cplusplus
}
#endif

#endif

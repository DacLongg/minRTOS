#include "mainApp.h"
#include "list.h"
#include "semaphore.h"
#include "mutex.h"

OS_task_t *Task1_handle;
OS_task_t *Task2_handle;
OS_task_t *Task3_handle;
OS_task_t *Task4_handle;
OS_task_t *Task5_handle;

uint16_t count1 = 0;
uint16_t count2 = 0;
uint16_t count3 = 0;
uint16_t count4 = 0;
uint16_t count5 = 0;

Semaphore_t* smpforcount1;

Mutex_t* mutex1;

void taskFunction1(void) {

//	smpforcount1 = SMP_create(SMP_COUNTING, 2);
	mutex1 = Mutex_create();
    while (1) {
        // Code của task 1
//    	SMP_Take(smpforcount1);
    	Mutex_Take(mutex1);
    	while( 1)
    	{

    		if(++ count1 == 10000)
    		{
    			count1 = 0;
    			break;
    		}

			task_sleep(1);
    	}
//    	SMP_Give(smpforcount1);
    	Mutex_Give(mutex1);
    	task_sleep(1);
    }
}

void taskFunction2(void) {


    while (1) {

    	Mutex_Take(mutex1);
    	while(1)
    	{
//    		SMP_Give(smpforcount1);
//    		DOS_TaskResume(Task5_handle);
    		if(++ count2 == 1000)
    		{
    			count2 = 0;
    			break;
    		}

    		task_sleep(1);
    	}
        // Code của task 2
    	Mutex_Give(mutex1);

    	task_sleep(1);
    }
}

void taskFunction3(void) {

    while (1) {
        // Code của task 1
//    	SMP_Take(smpforcount1);
    	Mutex_Take(mutex1);
    	while(1)
		{
    		if( ++ count3 >= 500)
    		{
    			count3 = 0;
    			break;
    		}
    		task_sleep(1);

		}
    	Mutex_Give(mutex1);
    	task_sleep(1);
    }
}

void taskFunction4(void) {

    while (1) {
        // Code của task 2
//    	SMP_Take(smpforcount1);
//    	Mutex_Take(mutex1);
    	if( ++ count4 == 500)
    	{

//    		Mutex_Give(mutex1);
    		count4 = 0;
    	}
    	task_sleep(1);
    }
}

void taskFunction5(void) {

    while (1) {
        // Code của task 2
//    	SMP_Take(smpforcount1);
//    	Mutex_Take(mutex1);
    	if( ++ count5 >= 15)
    	{
//    		Mutex_Give(mutex1);
    		count5 = 0;
    	}
//    	SMP_counting_Give(smpforcount1);
    	task_sleep(1);
    }
}




void mainApp(void)
{


	Init_os();

	Task1_handle = task_create(taskFunction1, "taskFunction1", 128, 7);
	Task2_handle = task_create(taskFunction2, "taskFunction2", 128, 6);
	Task3_handle = task_create(taskFunction3, "taskFunction3", 128, 5);
	Task4_handle = task_create(taskFunction4, "taskFunction4", 128, 7);
	Task5_handle = task_create(taskFunction5, "taskFunction5", 128, 7);

	DOS_start_kernel();
//	DOS_stop_kernel();

	while(1)
	{


	}
}






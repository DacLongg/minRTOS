################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../middlewares/Third_Party/FreeRTOS/Source/croutine.c \
../middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
../middlewares/Third_Party/FreeRTOS/Source/list.c \
../middlewares/Third_Party/FreeRTOS/Source/queue.c \
../middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c \
../middlewares/Third_Party/FreeRTOS/Source/tasks.c \
../middlewares/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./middlewares/Third_Party/FreeRTOS/Source/croutine.o \
./middlewares/Third_Party/FreeRTOS/Source/event_groups.o \
./middlewares/Third_Party/FreeRTOS/Source/list.o \
./middlewares/Third_Party/FreeRTOS/Source/queue.o \
./middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o \
./middlewares/Third_Party/FreeRTOS/Source/tasks.o \
./middlewares/Third_Party/FreeRTOS/Source/timers.o 

C_DEPS += \
./middlewares/Third_Party/FreeRTOS/Source/croutine.d \
./middlewares/Third_Party/FreeRTOS/Source/event_groups.d \
./middlewares/Third_Party/FreeRTOS/Source/list.d \
./middlewares/Third_Party/FreeRTOS/Source/queue.d \
./middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d \
./middlewares/Third_Party/FreeRTOS/Source/tasks.d \
./middlewares/Third_Party/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
middlewares/Third_Party/FreeRTOS/Source/%.o middlewares/Third_Party/FreeRTOS/Source/%.su middlewares/Third_Party/FreeRTOS/Source/%.cyclo: ../middlewares/Third_Party/FreeRTOS/Source/%.c middlewares/Third_Party/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/App/stm32/uart_dma/middlewares/data_structure/fifo" -I"D:/App/stm32/uart_dma/App" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"D:/App/stm32/uart_dma/middlewares/MiniOs_M3/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source

clean-middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source:
	-$(RM) ./middlewares/Third_Party/FreeRTOS/Source/croutine.cyclo ./middlewares/Third_Party/FreeRTOS/Source/croutine.d ./middlewares/Third_Party/FreeRTOS/Source/croutine.o ./middlewares/Third_Party/FreeRTOS/Source/croutine.su ./middlewares/Third_Party/FreeRTOS/Source/event_groups.cyclo ./middlewares/Third_Party/FreeRTOS/Source/event_groups.d ./middlewares/Third_Party/FreeRTOS/Source/event_groups.o ./middlewares/Third_Party/FreeRTOS/Source/event_groups.su ./middlewares/Third_Party/FreeRTOS/Source/list.cyclo ./middlewares/Third_Party/FreeRTOS/Source/list.d ./middlewares/Third_Party/FreeRTOS/Source/list.o ./middlewares/Third_Party/FreeRTOS/Source/list.su ./middlewares/Third_Party/FreeRTOS/Source/queue.cyclo ./middlewares/Third_Party/FreeRTOS/Source/queue.d ./middlewares/Third_Party/FreeRTOS/Source/queue.o ./middlewares/Third_Party/FreeRTOS/Source/queue.su ./middlewares/Third_Party/FreeRTOS/Source/stream_buffer.cyclo ./middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d ./middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o ./middlewares/Third_Party/FreeRTOS/Source/stream_buffer.su ./middlewares/Third_Party/FreeRTOS/Source/tasks.cyclo ./middlewares/Third_Party/FreeRTOS/Source/tasks.d ./middlewares/Third_Party/FreeRTOS/Source/tasks.o ./middlewares/Third_Party/FreeRTOS/Source/tasks.su ./middlewares/Third_Party/FreeRTOS/Source/timers.cyclo ./middlewares/Third_Party/FreeRTOS/Source/timers.d ./middlewares/Third_Party/FreeRTOS/Source/timers.o ./middlewares/Third_Party/FreeRTOS/Source/timers.su

.PHONY: clean-middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source


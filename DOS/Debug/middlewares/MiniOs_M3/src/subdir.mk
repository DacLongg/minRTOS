################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../middlewares/MiniOs_M3/src/OS_m3.s 

C_SRCS += \
../middlewares/MiniOs_M3/src/mini_task.c 

OBJS += \
./middlewares/MiniOs_M3/src/OS_m3.o \
./middlewares/MiniOs_M3/src/mini_task.o 

S_DEPS += \
./middlewares/MiniOs_M3/src/OS_m3.d 

C_DEPS += \
./middlewares/MiniOs_M3/src/mini_task.d 


# Each subdirectory must supply rules for building sources it contributes
middlewares/MiniOs_M3/src/%.o: ../middlewares/MiniOs_M3/src/%.s middlewares/MiniOs_M3/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"
middlewares/MiniOs_M3/src/%.o middlewares/MiniOs_M3/src/%.su middlewares/MiniOs_M3/src/%.cyclo: ../middlewares/MiniOs_M3/src/%.c middlewares/MiniOs_M3/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/App/stm32/uart_dma/middlewares/data_structure/fifo" -I"D:/App/stm32/uart_dma/App" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"D:/App/stm32/uart_dma/middlewares/MiniOs_M3/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-middlewares-2f-MiniOs_M3-2f-src

clean-middlewares-2f-MiniOs_M3-2f-src:
	-$(RM) ./middlewares/MiniOs_M3/src/OS_m3.d ./middlewares/MiniOs_M3/src/OS_m3.o ./middlewares/MiniOs_M3/src/mini_task.cyclo ./middlewares/MiniOs_M3/src/mini_task.d ./middlewares/MiniOs_M3/src/mini_task.o ./middlewares/MiniOs_M3/src/mini_task.su

.PHONY: clean-middlewares-2f-MiniOs_M3-2f-src


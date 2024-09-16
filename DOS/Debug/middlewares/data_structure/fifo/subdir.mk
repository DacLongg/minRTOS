################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../middlewares/data_structure/fifo/fifo.c 

OBJS += \
./middlewares/data_structure/fifo/fifo.o 

C_DEPS += \
./middlewares/data_structure/fifo/fifo.d 


# Each subdirectory must supply rules for building sources it contributes
middlewares/data_structure/fifo/%.o middlewares/data_structure/fifo/%.su middlewares/data_structure/fifo/%.cyclo: ../middlewares/data_structure/fifo/%.c middlewares/data_structure/fifo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/App/stm32/uart_dma/middlewares/data_structure/fifo" -I"D:/App/stm32/uart_dma/App" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"D:/App/stm32/uart_dma/middlewares/MiniOs_M3/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-middlewares-2f-data_structure-2f-fifo

clean-middlewares-2f-data_structure-2f-fifo:
	-$(RM) ./middlewares/data_structure/fifo/fifo.cyclo ./middlewares/data_structure/fifo/fifo.d ./middlewares/data_structure/fifo/fifo.o ./middlewares/data_structure/fifo/fifo.su

.PHONY: clean-middlewares-2f-data_structure-2f-fifo


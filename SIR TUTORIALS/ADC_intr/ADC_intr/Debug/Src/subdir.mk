################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/main.c \
../Src/pll.c \
../Src/serial.c \
../Src/sysTick.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/adc.o \
./Src/main.o \
./Src/pll.o \
./Src/serial.o \
./Src/sysTick.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/adc.d \
./Src/main.d \
./Src/pll.d \
./Src/serial.d \
./Src/sysTick.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/adc.d ./Src/adc.o ./Src/adc.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/pll.d ./Src/pll.o ./Src/pll.su ./Src/serial.d ./Src/serial.o ./Src/serial.su ./Src/sysTick.d ./Src/sysTick.o ./Src/sysTick.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src


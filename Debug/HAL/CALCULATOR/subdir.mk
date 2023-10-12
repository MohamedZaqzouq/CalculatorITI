################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/CALCULATOR/CALC_Prog.c 

OBJS += \
./HAL/CALCULATOR/CALC_Prog.o 

C_DEPS += \
./HAL/CALCULATOR/CALC_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/CALCULATOR/%.o: ../HAL/CALCULATOR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



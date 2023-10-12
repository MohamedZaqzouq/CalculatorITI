################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Keypad/subdir.mk
-include HAL/CALCULATOR/subdir.mk
-include APP/Projects/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
CalcuulatorITI.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: CalcuulatorITI.elf secondary-outputs

# Tool invocations
CalcuulatorITI.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,CalcuulatorITI.map -mmcu=atmega16 -o "CalcuulatorITI.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

CalcuulatorITI.lss: CalcuulatorITI.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S CalcuulatorITI.elf  >"CalcuulatorITI.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: CalcuulatorITI.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 CalcuulatorITI.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) CalcuulatorITI.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

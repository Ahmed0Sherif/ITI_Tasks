################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/M_DIO/subdir.mk
-include HAL/H_SEVEN/subdir.mk
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
D10_Task_02.lss \

FLASH_IMAGE += \
D10_Task_02.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: D10_Task_02.elf secondary-outputs

# Tool invocations
D10_Task_02.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,D10_Task_02.map -mmcu=atmega16 -o "D10_Task_02.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

D10_Task_02.lss: D10_Task_02.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S D10_Task_02.elf  >"D10_Task_02.lss"
	@echo 'Finished building: $@'
	@echo ' '

D10_Task_02.hex: D10_Task_02.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex D10_Task_02.elf  "D10_Task_02.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: D10_Task_02.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 D10_Task_02.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) D10_Task_02.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

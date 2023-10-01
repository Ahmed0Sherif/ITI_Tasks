################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/M_TMR/subdir.mk
-include MCAL/M_DIO/subdir.mk
-include MCAL/M_ADC/subdir.mk
-include MCAL/EXT_INT/subdir.mk
-include HAL/H_SERVO/subdir.mk
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
D17_Task2.lss \

FLASH_IMAGE += \
D17_Task2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: D17_Task2.elf secondary-outputs

# Tool invocations
D17_Task2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,D17_Task2.map -mmcu=atmega32 -o "D17_Task2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

D17_Task2.lss: D17_Task2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S D17_Task2.elf  >"D17_Task2.lss"
	@echo 'Finished building: $@'
	@echo ' '

D17_Task2.hex: D17_Task2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex D17_Task2.elf  "D17_Task2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: D17_Task2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 D17_Task2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) D17_Task2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/M_ADC/ADC_Program.c 

OBJS += \
./MCAL/M_ADC/ADC_Program.o 

C_DEPS += \
./MCAL/M_ADC/ADC_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/M_ADC/%.o: ../MCAL/M_ADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



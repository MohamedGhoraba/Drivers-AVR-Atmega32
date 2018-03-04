################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../EEPROM.c \
../I2C.c \
../Keypad.c \
../LCD.c \
../SPI.c \
../main.c \
../usart.c 

OBJS += \
./ADC.o \
./EEPROM.o \
./I2C.o \
./Keypad.o \
./LCD.o \
./SPI.o \
./main.o \
./usart.o 

C_DEPS += \
./ADC.d \
./EEPROM.d \
./I2C.d \
./Keypad.d \
./LCD.d \
./SPI.d \
./main.d \
./usart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



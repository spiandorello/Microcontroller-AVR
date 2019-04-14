################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../display/interrupt_led_display_mux.c \
../display/lcd.c \
../display/led_display.c \
../display/led_display_mux.c \
../display/led_table.c \
../display/serial_display.c 

OBJS += \
./display/interrupt_led_display_mux.o \
./display/lcd.o \
./display/led_display.o \
./display/led_display_mux.o \
./display/led_table.o \
./display/serial_display.o 

C_DEPS += \
./display/interrupt_led_display_mux.d \
./display/lcd.d \
./display/led_display.d \
./display/led_display_mux.d \
./display/led_table.d \
./display/serial_display.d 


# Each subdirectory must supply rules for building sources it contributes
display/%.o: ../display/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



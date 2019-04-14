################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lib/subdir.mk
-include display/subdir.mk
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
Serial_Display.lss \

FLASH_IMAGE += \
Serial_Display.hex \

EEPROM_IMAGE += \
Serial_Display.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Serial_Display.elf secondary-outputs

# Tool invocations
Serial_Display.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Serial_Display.map -mmcu=atmega328p -o "Serial_Display.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Serial_Display.lss: Serial_Display.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Serial_Display.elf  >"Serial_Display.lss"
	@echo 'Finished building: $@'
	@echo ' '

Serial_Display.hex: Serial_Display.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Serial_Display.elf  "Serial_Display.hex"
	@echo 'Finished building: $@'
	@echo ' '

Serial_Display.eep: Serial_Display.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Serial_Display.elf  "Serial_Display.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Serial_Display.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Serial_Display.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Serial_Display.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets

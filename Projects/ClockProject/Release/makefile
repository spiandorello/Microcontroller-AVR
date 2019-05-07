################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lib/subdir.mk
-include display/subdir.mk
-include clock/subdir.mk
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
ClockProject.lss \

FLASH_IMAGE += \
ClockProject.hex \

EEPROM_IMAGE += \
ClockProject.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ClockProject.elf secondary-outputs

# Tool invocations
ClockProject.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ClockProject.map -mmcu=atmega328p -o "ClockProject.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ClockProject.lss: ClockProject.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ClockProject.elf  >"ClockProject.lss"
	@echo 'Finished building: $@'
	@echo ' '

ClockProject.hex: ClockProject.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ClockProject.elf  "ClockProject.hex"
	@echo 'Finished building: $@'
	@echo ' '

ClockProject.eep: ClockProject.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ClockProject.elf  "ClockProject.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ClockProject.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p ClockProject.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ClockProject.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

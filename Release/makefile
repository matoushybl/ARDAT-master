################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ARDAT_master.lss \

FLASH_IMAGE += \
ARDAT_master.hex \

EEPROM_IMAGE += \
ARDAT_master.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ARDAT_master.elf secondary-outputs

# Tool invocations
ARDAT_master.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ARDAT_master.map -mmcu=atmega32 -o "ARDAT_master.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ARDAT_master.lss: ARDAT_master.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ARDAT_master.elf  >"ARDAT_master.lss"
	@echo 'Finished building: $@'
	@echo ' '

ARDAT_master.hex: ARDAT_master.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex ARDAT_master.elf  "ARDAT_master.hex"
	@echo 'Finished building: $@'
	@echo ' '

ARDAT_master.eep: ARDAT_master.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ARDAT_master.elf  "ARDAT_master.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ARDAT_master.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ARDAT_master.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) ARDAT_master.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

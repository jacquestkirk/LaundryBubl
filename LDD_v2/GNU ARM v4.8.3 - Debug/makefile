################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/efm32hg/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LDD_v2.axf

# Tool invocations
LDD_v2.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -T "LDD_v2.ld" -Xlinker --gc-sections -Xlinker -Map="LDD_v2.map" --specs=nano.specs -o LDD_v2.axf "./src/InitDevice.o" "./src/accel.o" "./src/buzzer.o" "./src/flashWriter.o" "./src/main.o" "./src/main_flashWriter.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_int.o" "./emlib/em_msc.o" "./emlib/em_system.o" "./CMSIS/efm32hg/startup_gcc_efm32hg.o" "./CMSIS/efm32hg/system_efm32hg.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: LDD_v2.hex'
	arm-none-eabi-objcopy -O ihex "LDD_v2.axf" "LDD_v2.hex"
	@echo ' '

	@echo 'Building bin file: LDD_v2.bin'
	arm-none-eabi-objcopy -O binary "LDD_v2.axf" "LDD_v2.bin"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "LDD_v2.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) LDD_v2.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

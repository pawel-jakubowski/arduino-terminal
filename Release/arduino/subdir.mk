################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arduino/SerialTerminal.cpp \
../arduino/test.cpp 

OBJS += \
./arduino/SerialTerminal.o \
./arduino/test.o 

CPP_DEPS += \
./arduino/SerialTerminal.d \
./arduino/test.d 


# Each subdirectory must supply rules for building sources it contributes
arduino/%.o: ../arduino/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/eightanaloginputs -I"/home/pjakubowski/workspaces/AVR/ArduinoNano_Console" -I/home/pjakubowski/workspaces/AVR/libraries -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



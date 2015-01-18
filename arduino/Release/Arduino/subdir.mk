################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Arduino/CDC.cpp \
../Arduino/HID.cpp \
../Arduino/HardwareSerial.cpp \
../Arduino/IPAddress.cpp \
../Arduino/Print.cpp \
../Arduino/Stream.cpp \
../Arduino/Tone.cpp \
../Arduino/USBCore.cpp \
../Arduino/WMath.cpp \
../Arduino/WString.cpp \
../Arduino/main.cpp \
../Arduino/new.cpp 

C_SRCS += \
../Arduino/WInterrupts.c \
../Arduino/wiring.c \
../Arduino/wiring_analog.c \
../Arduino/wiring_digital.c \
../Arduino/wiring_pulse.c \
../Arduino/wiring_shift.c 

OBJS += \
./Arduino/CDC.o \
./Arduino/HID.o \
./Arduino/HardwareSerial.o \
./Arduino/IPAddress.o \
./Arduino/Print.o \
./Arduino/Stream.o \
./Arduino/Tone.o \
./Arduino/USBCore.o \
./Arduino/WInterrupts.o \
./Arduino/WMath.o \
./Arduino/WString.o \
./Arduino/main.o \
./Arduino/new.o \
./Arduino/wiring.o \
./Arduino/wiring_analog.o \
./Arduino/wiring_digital.o \
./Arduino/wiring_pulse.o \
./Arduino/wiring_shift.o 

C_DEPS += \
./Arduino/WInterrupts.d \
./Arduino/wiring.d \
./Arduino/wiring_analog.d \
./Arduino/wiring_digital.d \
./Arduino/wiring_pulse.d \
./Arduino/wiring_shift.d 

CPP_DEPS += \
./Arduino/CDC.d \
./Arduino/HID.d \
./Arduino/HardwareSerial.d \
./Arduino/IPAddress.d \
./Arduino/Print.d \
./Arduino/Stream.d \
./Arduino/Tone.d \
./Arduino/USBCore.d \
./Arduino/WMath.d \
./Arduino/WString.d \
./Arduino/main.d \
./Arduino/new.d 


# Each subdirectory must supply rules for building sources it contributes
Arduino/%.o: ../Arduino/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/eightanaloginputs -I"/home/pjakubowski/workspaces/AVR/ArduinoNano_Console" -I/home/pjakubowski/workspaces/AVR/libraries -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Arduino/%.o: ../Arduino/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/eightanaloginputs -I"/home/pjakubowski/workspaces/AVR/ArduinoNano_Console" -I/home/pjakubowski/workspaces/AVR/libraries -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



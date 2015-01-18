################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arduino/arduino_libs/CDC.cpp \
../arduino/arduino_libs/HID.cpp \
../arduino/arduino_libs/HardwareSerial.cpp \
../arduino/arduino_libs/IPAddress.cpp \
../arduino/arduino_libs/Print.cpp \
../arduino/arduino_libs/Stream.cpp \
../arduino/arduino_libs/Tone.cpp \
../arduino/arduino_libs/USBCore.cpp \
../arduino/arduino_libs/WMath.cpp \
../arduino/arduino_libs/WString.cpp \
../arduino/arduino_libs/main.cpp \
../arduino/arduino_libs/new.cpp 

C_SRCS += \
../arduino/arduino_libs/WInterrupts.c \
../arduino/arduino_libs/wiring.c \
../arduino/arduino_libs/wiring_analog.c \
../arduino/arduino_libs/wiring_digital.c \
../arduino/arduino_libs/wiring_pulse.c \
../arduino/arduino_libs/wiring_shift.c 

OBJS += \
./arduino/arduino_libs/CDC.o \
./arduino/arduino_libs/HID.o \
./arduino/arduino_libs/HardwareSerial.o \
./arduino/arduino_libs/IPAddress.o \
./arduino/arduino_libs/Print.o \
./arduino/arduino_libs/Stream.o \
./arduino/arduino_libs/Tone.o \
./arduino/arduino_libs/USBCore.o \
./arduino/arduino_libs/WInterrupts.o \
./arduino/arduino_libs/WMath.o \
./arduino/arduino_libs/WString.o \
./arduino/arduino_libs/main.o \
./arduino/arduino_libs/new.o \
./arduino/arduino_libs/wiring.o \
./arduino/arduino_libs/wiring_analog.o \
./arduino/arduino_libs/wiring_digital.o \
./arduino/arduino_libs/wiring_pulse.o \
./arduino/arduino_libs/wiring_shift.o 

C_DEPS += \
./arduino/arduino_libs/WInterrupts.d \
./arduino/arduino_libs/wiring.d \
./arduino/arduino_libs/wiring_analog.d \
./arduino/arduino_libs/wiring_digital.d \
./arduino/arduino_libs/wiring_pulse.d \
./arduino/arduino_libs/wiring_shift.d 

CPP_DEPS += \
./arduino/arduino_libs/CDC.d \
./arduino/arduino_libs/HID.d \
./arduino/arduino_libs/HardwareSerial.d \
./arduino/arduino_libs/IPAddress.d \
./arduino/arduino_libs/Print.d \
./arduino/arduino_libs/Stream.d \
./arduino/arduino_libs/Tone.d \
./arduino/arduino_libs/USBCore.d \
./arduino/arduino_libs/WMath.d \
./arduino/arduino_libs/WString.d \
./arduino/arduino_libs/main.d \
./arduino/arduino_libs/new.d 


# Each subdirectory must supply rules for building sources it contributes
arduino/arduino_libs/%.o: ../arduino/arduino_libs/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/eightanaloginputs -I"/home/pjakubowski/workspaces/AVR/ArduinoNano_Console" -I/home/pjakubowski/workspaces/AVR/libraries -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/arduino_libs/%.o: ../arduino/arduino_libs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/eightanaloginputs -I"/home/pjakubowski/workspaces/AVR/ArduinoNano_Console" -I/home/pjakubowski/workspaces/AVR/libraries -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



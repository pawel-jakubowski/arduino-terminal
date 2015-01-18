################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ArduinoTerminal.cpp \
../src/MutexLock.cpp \
../src/Serial.cpp 

OBJS += \
./src/ArduinoTerminal.o \
./src/MutexLock.o \
./src/Serial.o 

CPP_DEPS += \
./src/ArduinoTerminal.d \
./src/MutexLock.d \
./src/Serial.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



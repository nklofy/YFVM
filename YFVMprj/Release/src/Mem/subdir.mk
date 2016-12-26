################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Mem/Allocr.cpp \
../src/Mem/GC.cpp \
../src/Mem/MemManager.cpp \
../src/Mem/Memory.cpp 

OBJS += \
./src/Mem/Allocr.o \
./src/Mem/GC.o \
./src/Mem/MemManager.o \
./src/Mem/Memory.o 

CPP_DEPS += \
./src/Mem/Allocr.d \
./src/Mem/GC.d \
./src/Mem/MemManager.d \
./src/Mem/Memory.d 


# Each subdirectory must supply rules for building sources it contributes
src/Mem/%.o: ../src/Mem/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



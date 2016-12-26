################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RT/Frame.cpp \
../src/RT/Heap.cpp \
../src/RT/StaticPool.cpp \
../src/RT/VM.cpp 

OBJS += \
./src/RT/Frame.o \
./src/RT/Heap.o \
./src/RT/StaticPool.o \
./src/RT/VM.o 

CPP_DEPS += \
./src/RT/Frame.d \
./src/RT/Heap.d \
./src/RT/StaticPool.d \
./src/RT/VM.d 


# Each subdirectory must supply rules for building sources it contributes
src/RT/%.o: ../src/RT/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



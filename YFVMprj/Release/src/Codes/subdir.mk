################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Codes/CodeBlock.cpp \
../src/Codes/IRCode.cpp 

OBJS += \
./src/Codes/CodeBlock.o \
./src/Codes/IRCode.o 

CPP_DEPS += \
./src/Codes/CodeBlock.d \
./src/Codes/IRCode.d 


# Each subdirectory must supply rules for building sources it contributes
src/Codes/%.o: ../src/Codes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


